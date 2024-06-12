#include<bits/stdc++.h>
using namespace std;
int check(int data[99999],int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(data[i]>data[i+1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	int data[99999];
	int a;
	scanf(" %d",&n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&data[i]);
	}
	int nub=0;
	while(!check(data,n))
	{
		for(int i=0;i<n;i++)
		{
			int k=data[i];
			int t=rand()%n;
			data[i]=data[t];
			data[t]=k;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",data[i]);
	}
}
