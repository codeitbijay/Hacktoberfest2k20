#include<iostream>
using namespace std;
int firstocc(int *a,int i,int n, int k)
{
    if(i==n)
    {
        return -1;
    }
    if(a[i]==k)
    {
        return i;
    }
    firstocc(a,i+1,n,k);
    
}
int lastind(int *a,int n,int k)
{
    if(n==0)
    {
        return -1;
    }
    int i=lastind(a+1,n-1,k);
    if(i==-1)
    {
        if(a[0]==k)
        {
            return 0;
        }
        else{
            return -1;
        }
    }
    return i+1;
}
int storeocc(long int *a,int i,long int n,long int k,int *out,long int j)
{
    if(i==n)
    {
        return j;
    }
    if(a[i]==k)
    {
        out[j]=i;
        return storeocc(a,i+1,n,k,out,j+1);
    }
        return storeocc(a,i+1,n,k,out,j);
}
void alloc(long int *a,int i,long int n,long int k)
{
    if(i==n)
    {
        return;
    }
    if(a[i]==k)
    {
        cout<<i<<endl;
    }
    return alloc(a,i+1,n,k);
}
int main()
{
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>k;
    cout<<firstocc(a,0,n,k);
    /*
     // alloc(a,0,n,k);
    int out[1000];
    int c=storeocc(a,0,n,k,out,0);
    for(int i=0;i<c;i++)
    {
        cout<<out[j]<<endl;
    }
    */
}
