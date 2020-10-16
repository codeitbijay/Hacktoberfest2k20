#include<iostream>
using namespace std;
int lastoc(int *arr,int n,int k)
{
	if(n==0)
	{
		return -1;
	}
	//rec
	int i=lastoc(arr+1,n-1,k);
	if(i==-1)
	{
	    if(arr[0]==k)
        {
	        return 0;
        }
        else{
	        return -1;
        }
    }
	return i+1;  // returning 0
}
int main()
{
	int n=10;
	int arr[]={1,3,7,8,9,7,5,4,7,2};
	int k=7;
	cout<<lastoc(arr,n,k)<<endl;// 8
	return 0;
}
