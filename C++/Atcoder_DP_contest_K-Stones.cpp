#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll const mod = 1e9+7;
ll const N = 50;
ll const inf = 2e16;
#define UNASSIGNED -1
ll n0,k0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a,b,c,d,e,f,x,n,m,p,k,t,q;
    t=1;
    //cin>>t;
    //string s1,s2,s3;
    //simpleprime(sqrt(1000000000)+1);
	for(ll t0=0;t0<t;t0++)
    {
        cin>>n>>k;
        n0=n;
        k0=k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<bool> dp(k+1);
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-arr[j]>=0&&!dp[i-arr[j]])
                {
                dp[i]=true;
                }
            }
        }
        if(dp[k]) 
        cout<<"First\n";
        else 
        cout<<"Second\n";
    }
    return 0;
}
