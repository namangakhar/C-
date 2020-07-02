/* One bad fish can spoilt the whole pond . This is a program to determine in how many days all oranges will go bad in a square crate. if an orange is
rip then it makes all the surrounding oranges rip, we can even keep a pocket of sq crate empty to stop the spread of riping oranges */
#include<iostream>
using namespace std;
int main()
{	int n,n1;
	cout<<"enter the square crate size : ";
	cin>>n1;
	n=n1*n1;
	int crate[n-1];	
	cout<<"Enter orange type for each location"<<endl<<"press 0 at empty pocket 1 for rip oranges and 2 for fresh oranges"<<endl;
	int i,p,m;
	for(i=0;i<n;i++)
	{
		cout<<"at "<<i/n1<<","<<i%n1<<" : ";
		cin>>crate[i];
	}
	
	//printing
	cout<<"\n";
	cout<<"basket is:"<<endl;
	for(i=0;i<n;i++)
	{
	cout<<crate[i];
	if((i+1)%n1==0)
	cout<<endl;
}
	cout<<endl;
	//solving
	int ij[n*n],k,steps=0;
	do{
		for(i=0;i<n;i++)
		ij[i]=-1;
		k=0;
		m=0;
		for(i=0;i<n;i++)
		{
		
			if (crate[i]==1 )
			{
				ij[k]=i;
				k++;
			}
		}
		for(i=0;ij[i]!=-1;i++)
		{
			if(crate[ij[i]+n1]==2)
			{
				crate[ij[i]+n1]=1;
				m++;
			}
			else if(crate[ij[i]-n1]==2)
			{
				crate[ij[i]-n1]=1;
				m++;
			}
			if(crate[ij[i]+1]==2 && (ij[i]+1)%n1)
			{
				crate[ij[i]+1]=1;
				m++;
			}
			if(crate[ij[i]-1]==2 && (ij[i])%n1)
			{
				crate[ij[i]-1]=1;
				m++;
			}
		}
		if(m)
		steps++;
	}while(m);
	cout<<endl<<"total days taken = "<<steps<<endl;
	cout<<"basket at the end is:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<crate[i];
		if((i+1)%n1==0)
		cout<<endl;
	}
	 
}
