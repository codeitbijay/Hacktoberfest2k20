#include<bits/stdc++.h>
using namespace std;
int minimum(vector <int> c,int n)
{
    int min=c[0],index;
    for(int i=1;i<n;i++)
    {
        if(c[i]<min)
        {
            min=c[i];
            index=i;
        }
    }
    return index;
}
void fcfs(int a[],int c,int n,int p)
{
    int seek=0;
    for(int i=0;i<n;i++)
    {
        seek+=abs(a[i]-p);
        p=a[i];
    }
    cout<<"\n Sequence of head movement ....";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<"\n Total head Movements = "<<seek;
}
void sstf(int a[],int c,int n, int p)
{
    int seek=0,index=0;
    vector<int> b(n);
    for(int i=0;i<n;i++)
    {
    	b[i]=a[i];
	}
	cout<<"\n Sequence of head movement ....\n";
	for(int i=0;i<n;i++)
	{
		vector <int> c;
		for(int i=0;i<b.size();i++)
		{
			c.push_back(abs(b[i]-p));
		}
		index=minimum(c,c.size());
		seek+=abs(b[index]-p);	
		p=b[index];
        cout<<p<<"\t";
    	b.erase(b.begin()+index);
	}
	cout<<"\n Total head Movements = "<<seek;
}
void scan(int a[],int c,int n, int p)
{
    int seek=0,index=0;
    vector<int> b(n+1);
    for(int i=0;i<n;i++)
    {
    	b[i]=a[i];
	}
	b[n]=p;
    sort(b.begin(),b.end());
    for(int i=0;i<=n;i++)
    {
    	if(p==b[i])
    	{
    		index=i;break;
		}
	}
	cout<<"\n Sequence of head movement ...\n";
	for(int i=index+1;i<=n;i++)
	{
		cout<<b[i]<<"\t";
	}
	for(int i=index-1;i>=0;i--)
	{
		cout<<b[i]<<"\t";
	}
	if(index==0)
	{
		seek=b[n];
	}
	else if(index==n)
	{
		seek=b[0];
	}
	else
	{
		seek+=c-b[index];
		seek+=c-b[0];
	}
	cout<<"\n Total head Movements = "<<seek;
}
void c_scan(int a[],int c,int n, int p)
{
    int seek=0,index=0;
    vector<int> b(n+1);
    for(int i=0;i<n;i++)
    {
    	b[i]=a[i];
	}
	b[n]=p;
    sort(b.begin(),b.end());
    for(int i=0;i<=n;i++)
    {
    	if(p==b[i])
    	{
    		index=i;break;
		}
	}
	cout<<"\n Sequence of head movement ...\n";
	for(int i=index+1;i<=n;i++)
	{
		cout<<b[i]<<"\t";
	}
	for(int i=0;i<index;i++)
	{
		cout<<b[i]<<"\t";
	}
	if(index==0)
	{
		seek=b[n];
	}
	else if(index==n)
	{
		seek=c+b[n-1];
	}
	else
	{
		seek+=c-b[index];
		seek+=c-1;
		seek+=b[index-1]-1;
	}
	cout<<"\n Total head Movements = "<<seek;
}
void look(int a[],int c,int n, int p)
{
    int seek=0,index=0;
    vector<int> b(n+1);
    for(int i=0;i<n;i++)
    {
    	b[i]=a[i];
	}
	b[n]=p;
    sort(b.begin(),b.end());
    for(int i=0;i<=n;i++)
    {
    	if(p==b[i])
    	{
    		index=i;break;
		}
	}
	cout<<"\n Sequence of head movement ...\n";
	for(int i=index+1;i<=n;i++)
	{
		cout<<b[i]<<"\t";
	}
	for(int i=index-1;i>=0;i--)
	{
		cout<<b[i]<<"\t";
	}
	if(index==0)
	{
		seek=b[n];
	}
	else if(index==n)
	{
		seek=b[0];
	}
	else
	{
		seek+=b[n]-b[index];
		seek+=b[n]-b[0];
	}
	cout<<"\n Total head Movements = "<<seek;
}
void c_look(int a[],int c,int n, int p)
{
    int seek=0,index=0;
    vector<int> b(n+1);
    for(int i=0;i<n;i++)
    {
    	b[i]=a[i];
	}
	b[n]=p;
    sort(b.begin(),b.end());
    for(int i=0;i<=n;i++)
    {
    	if(p==b[i])
    	{
    		index=i;break;
		}
	}
	cout<<"\n Sequence of head movement ...\n";
	for(int i=index+1;i<=n;i++)
	{
		cout<<b[i]<<"\t";
	}
	for(int i=0;i<index;i++)
	{
		cout<<b[i]<<"\t";
	}
	if(index==0)
	{
		seek=b[n];
	}
	else if(index==n)
	{
		seek+=b[n]-b[0];
		seek+=b[n-1];
	}
	else
	{
		seek+=b[n]-b[index];
		seek+=b[n]-b[0];
		seek+=b[index-1]-b[0];		
	}
	cout<<"\n Total head Movements = "<<seek;
}
int main()
{
    int cyl,req,curr_pos=0;
    cout<<"\n Enter number of cylinders in the disk : ";
    cin>>cyl;
    cout<<"\n Enter number of requests : ";
    cin>>req;
    cout<<"\n Enter currrent position of the head of the disk : ";
    cin>>curr_pos;
    int r[req];
    cout<<"\n Enter the request queue ...\n";
    for(int i=0;i<req;i++)
    {
        cin>>r[i];
    }
    int w;
    cout<<"\n Scheduling Algorithms to Apply on disk requests ... \n 1.FCFS \n 2.SSTF \n 3.SCAN \n 4.C-SCAN \n 5.LOOK \n 6.C-LOOK";
    cout<<"\n Enter your choice : ";
    cin>>w;
    switch (w)
    {
    case 1:fcfs(r,cyl,req,curr_pos);break;
    case 2:sstf(r,cyl,req,curr_pos);break;
    case 3:scan(r,cyl,req,curr_pos);break;
    case 4:c_scan(r,cyl,req,curr_pos);break;
    case 5:look(r,cyl,req,curr_pos);break;
    case 6:c_look(r,cyl,req,curr_pos);break;    
    default: cout<<"\n Invalid Choice ...";break;
    }
    return 0;
}
