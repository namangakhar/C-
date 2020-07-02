#include<iostream>
/* Any movement of can be shown as moving across a grid with small enough size of a single block. This is a program where the princess is captured and 
is kept somewhere with walls/river anything imagiable as obstacles , the prince stands at block 1 ie his castle and needs to go the princess avoiding
obstacles and save her   */
using namespace std;

int blockcheck(int x,int *bl,int tbl)							//Block checker
{
		for(int k=0;k<=tbl;k++)
		{
			if(x==bl[k])
			{
			return 1;
		}
		}
		return 0;
}
void pathwithob(int n, int r,int *block){
	int m,tblock=-1;											//Printing the path with obstacles
	for(int i=1;i<=n;i++)							
	{
		for(int j=1;j<=n;j++)
		{
			m=(j+(n*(i-1)));
			if(m==1||m==r)
			cout<<"P\t";
			else if(blockcheck(m,block,tblock))
				cout<<"O"<<"\t";
			else
				cout<<m<<"\t";
		}
		cout<<endl;
	}	
}
	

maze(int n)
{
	int r,size=n*n;								//entering the destintion
	do	{
		cout<<"\nThe Path will begin from 1"<<"\n\nEnter the destination number{location of princess} = ";
		cin>>r;
		if(r>size || r<1)
		cout<<endl<<"invalid entry : please enter a valid entry"<<endl;
		}
	while(r>size || r<0);

// can use this if we  need to put rows and columns
/*	do	{
		int c;
		cout<<"\n\n  Enter column of Destination {columns are vertical} =";
		cin>>c;
		}
	while(c>n || c<0);
*/	
int path[size];										//defining path and blocked arrays
	int block[size];
	int tpath=0,tblock=-1;
	path[tpath]=1;
	int q=1,h=1;										//defining obstructions
	cout<<"Enter Obstructions {obstuctions are blocks prince cannot step onto while moving} "<<endl<<"if done press 0"<<endl;
	while(q!=0)
	{
		if(tblock<=size)
		{
			cout<<"enter position of obstruction block "<<h<<" :";
			cin>>q;
			if( q!=r && q!=1)
			{
				tblock+=1;
				block[tblock]=q;
				h+=1;
			}
			else 
			{
				cout<<"You cant put obstuction at initial position of prince or Queen"<<endl;
			}
		}
		else
			cout<<"all blocks filled";
	}
	
	cout<<"\n The prince is at "<<"1"<<" to save the princess needs to reach "<<r<<endl<<"The following shows the map with O showing an obstruction and P denoting position of prince and the princess"<<endl;
	pathwithob(n,r,block);
	int count=0;
	int i=1,j;
	while(count!=1&&tpath>=0)
	{
		if(path[tpath]==r)
		{count=1;																					//checking if destination reached
		break;}
		
		
{
		if(i%n && !(blockcheck(i+1,block,tblock)) && !(blockcheck(i+1,path,tpath)))					//checking right side of i
		{
			i+=1;
			tpath+=1;
			path[tpath]=i;
			continue;
		};
		
		if(i<=(size-n) && !(blockcheck(i+n,block,tblock)) && !(blockcheck(i+n,path,tpath)))			//checking down
		{
			i+=n;
			tpath+=1;
			path[tpath]=i;
			continue;
		}
		
		if(i%(n)!=1 && !(blockcheck(i-1,block,tblock)) && !(blockcheck(i-1,path,tpath)))			//checking left
		{
			i-=1;
			tpath+=1;
			path[tpath]=i;
			continue;
		}
		
		if(i>n && !(blockcheck(i-n,block,tblock)) && !(blockcheck(i-n,path,tpath)))					//checking up
		{

			i-=n;
			tpath+=1;
			path[tpath]=i;
			continue;
		}

		tpath-=1;
		tblock+=1;
		block[tblock]=i;
		i=path[tpath];
}
	}
	
	if(count)
	{
		cout<<"Path to destination is : "<<endl;
		for(int i=0;i<=tpath;i++)
		{
			cout<<"move to "<<path[i]<<endl;
		}
	}
	else
		cout<<"no path btw prince and princess :";
	pathwithob(n,r,block);
}


int main()
{
	int n;
	cout<<"\t\t\t Welcome to save the princess"<<endl<<"Enter the square maze size : ";
	cin>>n;			//input the maze size
	cout<<endl<<"maze will look like this\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<(j+(n*(i-1)))<<"\t";
		}
		cout<<endl;
	}
	maze(n)	;		//calling the maze function
	
	
	
}
