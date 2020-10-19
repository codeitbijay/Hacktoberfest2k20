#include<iostream>
using namespace std;
int binarysearch(int arr[], int num, int start, int end)
{   while(start<=end){
    int middle = (start+end)/2;
        if(arr[middle] == num)
           return middle;
        if(arr[middle]>num)
           end=middle-1;
        else
           start=middle+1;
       
           }
   return -1;
}

int main()
{
   int arr[]={1,2,6,7,8,10};
   int num;
   cin>>num;
   int n = sizeof(arr)/ sizeof(arr[0]);
   int ans=binarysearch(arr,num,0,n-1);
   cout<<ans;

   return 0;
}
