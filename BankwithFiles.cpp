//Self Service kiosks for banks
#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;
fstream fout;
class account
{
	static int accnumber;
	int accno,balance;
	int a[5]={0,0,0,0,0};
	char name[20],type[9],password[20];
	public:
	void setacc(char *nme,int initb)
	{			
		accnumber++;
		accno=accnumber;
		strcpy(name,nme);
		if(initb==1)
		strcpy(type,"Checking");
		else
		strcpy(type,"Savings");
		cout<<"Enter Password For Your account : ";
		cin>>password;
		cout<<"account opened with balance 500."<<endl;
		balance=500;
		addtrans(500);
	}
	void deposit()
	{
		int n;
		cout<<"Enter amount to be deposited : ";
		cin>>n;
		if(n>0)
		{
		balance+=n;
		cout<<"Amount "<<n<<" deposited."<<endl;
		addtrans(n);
		}
	}
	void withdraw()
	{
		int n;
		cout<<"Enter amount to be withdrawn : ";
		cin>>n;
		if(n>0&&n<balance)
		{
		balance-=n;
		cout<<"Amount "<<n<<" Withdrawn."<<endl;
		addtrans(n*-1);
		}
		else
		cout<<"Not enough balance.";
	}
	void accdetails()
	{
		cout<<"This account number "<<accno<< " belongs to "<<name<<" and has Rs"<<balance<<type<<" in it"<<endl;
	}
	bool isacc(int x,char *pass)
	{
		if(x-accno==0&&strcmp(password,pass)==0)
		return true;
		return false;
	}
	void setaccnumber(int i)
	{
	accnumber+=i;
	}
	void transactions();
	void addtrans(int n);
};
int account::accnumber=1000;
void account::addtrans(int n)
{
	for(int i=3;i>=0;i--)
	a[i+1]=a[i];
	a[0]=n;	
}
void account::transactions()
{
	for(int i=0;i<5;i++)
	cout<<i+1<<". "<<a[i]<<endl;
}
void newaccount();
bool setup(account&);
void end(account &abc);
void readaccount();
void endr(account &abc,int i);

int main()
{
	account a;
	fout.open("bankwithfiles.txt",ios::ate|ios::out|ios::in|ios::binary);
	fout.seekg(0,ios::end);
	a.setaccnumber(fout.tellg()/sizeof(a));
	a.~account();
	fout.close();
	
	int x=1;
	while(x!=0){
		cout<<"Press."<<endl<<"1. to open a new account"<<endl<<"2.to load a new account"<<endl<<"0. to end program"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:newaccount();break;
			case 2:readaccount();break;
			case 0:break;
			default:
			{cout<<"enter a valid input";}
		}
	}	
}

void newaccount()
{
		
	cout<<endl<<endl;
	int x=1;
	account abc;
	fout.open("bankwithfiles.txt",ios::app|ios::out|ios::binary);
	if(setup(abc)){
	while(x!=0){
		cout<<"Press."<<endl<<"1.Deposit amount"<<endl<<"2.Withdraw amount"<<endl<<"3.Last 5 transactions"<<endl<<"4.Account details"<<endl<<"0 return to main menu"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:abc.deposit();break;
			case 2:abc.withdraw();break;
			case 3:abc.transactions();break;
			case 4:abc.accdetails();break;
			case 0:end(abc);break;
			default:
			{cout<<"enter a valid input";}
		}
	}
	}
}
void end(account &abc)
{
	cin.ignore();
	fout.write((char*)&abc,sizeof(abc));
	fout.close();	
}
bool setup(account &n)
{
	char name[20];
	int c;
	cin.ignore();
	cout<<"Enter name of Account holder : ";
	cin.getline(name,20);
	cout<<"1. Checking Account \n2. Savings Account\nPress number option: ";
	cin>>c;
	if(c!=1 && c!=2)
	{cout<<"failed to open account. ";
	return false;
	}
	else
	{
		n.setacc(name,c);
		return true;
	}
}
void readaccount()
{
	fout.open("bankwithfiles.txt",ios::ate|ios::out|ios::in|ios::binary);
	fout.seekg(0,ios::beg);
	account a;
	int x,x1=1;
	char pass[20];
	cout<<"Enter account number : ";cin>>x;
	cout<<"Enter password : ";cin>>pass;
	fout.seekg(0,ios::end);
	int n=fout.tellg()/sizeof(a);
	//cout<<n<<fout.tellg()<<" "<<sizeof(a);
	
	
	fout.seekg(0,ios::beg);
	for(int i=0;i<n;i++)
	{
	fout.read((char*)&a,sizeof(a));
	if(a.isacc(x,pass))
		{
			while(x1!=0){
			cout<<"Press."<<endl<<"1.Deposit amount"<<endl<<"2.Withdraw amount"<<endl<<"3.Last 5 transactions"<<endl<<"4.Account details"<<endl<<"0 return to main menu"<<endl;
			cin>>x1;
			switch(x1)
				{
					case 1:a.deposit();break;
					case 2:a.withdraw();break;
					case 3:a.transactions();break;
					case 4:a.accdetails();break;
					case 0:endr(a,i*sizeof(a));break;
					default:
					{cout<<"enter a valid input";}
				}
			}
		}
	}
	if(x1)
	cout<<"No account found."<<endl;
}
void endr(account &abc,int i)
{
	fout.seekg(i,ios::beg);
	end(abc);
}
	
