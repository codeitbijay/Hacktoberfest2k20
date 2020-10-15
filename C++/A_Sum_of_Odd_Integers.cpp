#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ll long long 
#define testcase long long t; cin>>t;

int main()
{
    testcase;
    while(t--){
      ll n,k;
      cin>>n>>k;
      if(k*k <= n && n%2== k%2) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;  
    }    
}