#include<bits/stdc++.h>
using namespace std;

void recurse_insertion(int a[],int n,int i){
        
        if(i==n)
            return;
        int temp = a[i];
        int j = i-1;
        while(j>= 0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }   
        a[j+1]=temp;
        recurse_insertion(a,n,i+1);
    
}

int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    int i=0;
    while(i<n)
    {
        cin>>b[i];
        i++;
    }

    recurse_insertion(b,n,0);
    cout<<"\nAfter Sorting\n";
    for(int i=0;i<n;i++)
    cout<<b[i]<<" ";

    return 0;
}