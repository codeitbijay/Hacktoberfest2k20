#include<bits/stdc++.h>
using namespace std;
int main()
{
	int pf,n,num,page_faults=0;
	char ch='y';
	cout<<"\n Enter Number of Page frames : ";
	cin>>pf;
	queue <int> q;
	bool hash[1000];
	cout<<"\n Enter no of page requests : ";
	cin>>n;
	cout<<"\n Enter Request queue ...\n";
	for(int i=0;i<n;i++)
	{
		cin>>num;
		if(q.size()<pf)
		{			
			if(!hash[num])
			{
				q.push(num);
				hash[num]=true;
				page_faults++;
			}				
		}
		else
		{
			if(!hash[num])
			{
				hash[q.front()]=false;
				q.pop();
				q.push(num);
				hash[num]=true;
				page_faults++;				
			}
		}	
	}	
	cout<<"\n Number of Page Faults = "<<page_faults;
	return 0;
}
