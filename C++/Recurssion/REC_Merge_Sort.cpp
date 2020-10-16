#include<iostream>
using namespace std;
void merge(long long int *a,long long int s,long long int e)
{
	long long int mid=(s+e)/2;
	long long int i=s;
	long long int j=mid+1;
	long long int k=0;  //imp: not to assign s
	long long int temp[e-s+1];  // size matters
	while(i<=mid and j<=e)   
	{
		if(a[i]<a[j])
		{
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[j++];
		}
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=e)
	{
		temp[k++]=a[j++];
	}
	for(long long int i=s;i<=e;i++)
	{
		a[i]=temp[i-s]; //change indexing
	}
}
void mergesort(long long int *a,long long int s,long long int e)
{
	if(s>=e)
	{
		return ;
	}
	long long int mid=(s+e)/2;
	//divide in 2 by 2 calls
	mergesort(a,s,mid);
	mergesort(a,mid+1,e);
	//merge
	merge(a,s,e);
}
int main() 
{
	long long int n;
	cin>>n;
	long long int a[n];
	for(long long int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	for(long long int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
