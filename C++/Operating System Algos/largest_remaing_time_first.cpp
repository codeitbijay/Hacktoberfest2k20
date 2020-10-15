#include<bits/stdc++.h>
using namespace std;
struct process
{
	int pid;
	int bt;
};
void swap(struct process &a, struct process &b) 
{ 
    int temp1,temp2;
    temp1=a.pid;
    a.pid=b.pid;
    b.pid=temp1;
    temp2=a.bt;
    a.bt=b.bt;
    b.bt=temp2;
} 
void bubbleSort(struct process *,int ); 
int main()
{
	float avwt=0,avtat=0;
	int n;
	cout<<"\n Enter Number of Processes : ";
	cin>>n;
	struct process p[n];
	int wt[n]={},tat[n]={};
	cout<<"\n Enter Details of Processes ...";
	for(int i=0;i<n;i++)
	{
		cout<<"\n Enter process id : ";
		cin>>p[i].pid;
		cout<<" Enter Burst time : ";
		cin>>p[i].bt;
	}
	bubbleSort(p,n);
	/*for(int i=0;i<n;i++)
	{
		cout<<p[i].pid<<"\t"<<p[i].bt<<endl;
	}*/
	for(int i=1;i<n;i++)
    {
        wt[i]=0;
        for(int j=0;j<i;j++)
            wt[i]+=p[j].bt;
    } 
    for(int i=0;i<n;i++)
    {
        tat[i]=p[i].bt+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"\n"<<p[i].pid<<"\t\t"<<p[i].bt<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
    
    avwt/=n;
    avtat/=n;
    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat;
	return 0;
}



void bubbleSort(struct process p[],int n) 
{ 
    int swapped, i; 
    do
    { 
        swapped = 0; 
        for(int i=0;i<n-1;i++)
        {
        	for(int j=0;j<n-1-i;j++)
        	{
        		if(p[j].bt==p[j+1].bt)
        		{
        			if(p[j].pid>p[j+1].pid)
        			{
        				swap(p[j],p[j+1]);
        				swapped=1;
					}
				}
				else if(p[j].bt<p[j+1].bt)
				{
					swap(p[j],p[j+1]);
					swapped=1;
				}
			}
		}
    } 
    while (swapped); 
} 
