#include<bits/stdc++.h>
using namespace std;

void recurse_bubble(int a[], int n)
{
    if(n==1)
        return;
    bool is_sorted = true;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            int temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            is_sorted=false;
        }
    }
    if(!is_sorted)
        recurse_bubble(a,n-1);
}

int main()
{
    int n,i=0;
    cin>>n;
    int b[n];
    while(i<n)
    {
        cin>>b[i];
        i++;
    }
    recurse_bubble(b,n);
    
    cout<<"\nAfter Sorting \n";
    for(i=0;i<n;i++)
    cout<<b[i]<<" ";
    
    return 0;
}