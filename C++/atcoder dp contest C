#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test int t; cin>>t; while(t--)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define f0(i,n) for( ll i = 0; i < ( n ); i ++)
#define f1(i,n) for(i = 1; i <= ( n ); i ++)
#define f(i,m,n) for(auto i = ( m ); i <= ( n ); i ++)
#define nl cout<<"\n"
#define  mod 1000000007
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define rall(v) v.rbegin(), v.rend()
#define SZ(x) ((ll)x.size())
#define mem(a, b) memset(a, b, sizeof(a));
#define make_graph(k) int x,y; f0(i,k){cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
#define dekh cout<<"dekh"

#define o_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define o_setpll tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
typedef vector<ll> vl;


ll n,k;
ll a[100005], b[100005], c[100005];
ll dp[100005][5];
ll solve(ll i, ll ch)
{
    if(i>=n)return 0;
    if(dp[i][ch]!=-1)return dp[i][ch];
    ll ans;
    if(ch==1)
    {
         ans = max(solve(i+1 ,2)+ a[i], solve(i+1,3 )+a[i]);
    }

    else if(ch==2)
    {
         ans = max(solve(i+1 ,1)+ b[i], solve(i+1,3 )+b[i]);
    }

    else if(ch==3)
    {
        ans = max(solve(i+1 ,2)+ c[i], solve(i+1,1 )+c[i]);
    }


        return dp[i][ch]=ans;


}

int main()
{
    fast
 mem(dp,-1);
   cin>>n;
   f0(i,n)
   {
       cin>>a[i]>>b[i]>>c[i];
   }
       ll ans1 = solve(0,1);
       ll ans2 = solve(0,2);
       ll ans3 = solve(0,3);
       cout<<max(ans1,max(ans2,ans3));


}



