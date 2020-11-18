#include <bits/stdc++.h>
#define lli long long int
#define fl(i,a,b) for (i=a ; i<b ; i++)
using namespace std;
int main()
{
    lli t;
    cin>>t;
    while (t--)
    {
        lli n,k;
        cin>>n>>k;
        lli arr[n],i,j;
        fl (i,0,n)
        {
            cin>>arr[i];
        }
        lli l=0,r=0;
        lli sum=0;
        lli check=0;
        while (check!=0)
        {
            sum=arr[l]+arr[r];
            if (sum<k)
                r++;
            else if (sum>k)
                l++;
        }
    }

    return 0;
}
