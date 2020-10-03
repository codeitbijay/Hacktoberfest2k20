#include<bits/stdc++.h>
using namespace std;

void recurse_selection(int a[], int n, int index)
{
    if (index ==n)
        return;
    int min_index=index, i=index;
    while(i<n)
    {
        if(a[i]<a[min_index])
            min_index=i;
        i++;
    }
    if(min_index != index)
    {
        a[min_index] = a[min_index] + a[index];       
        a[index] = a[min_index] - a[index]; 
        a[min_index] = a[min_index] - a[index];
    }
    recurse_selection(a, n, index+1);
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

    recurse_selection(b,n,0);

    cout<<"\nAfter Sorting\n";
    for(int i=0;i<n;i++)
    cout<<b[i]<<" ";
       
    return 0;
}
