#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
vector<string > v;
int crs[19][19];

int n;
int dp[19][(1<<19)];

int sol(int idx, int mask){
    int &t = dp[idx][mask];
    if(t != -1) return t;
    
    int flag =0 ;
    t = INT_MAX;
    for(int i=0 ; i<n ; i++){
        if(!(mask & (1 << i))){
            flag = 1;
    t = min (t, (int)v[i].size()-crs[idx][i] + sol(i, mask | (1<<i) ) );
        }
    }
    if(flag==0) t = 0;
    return t;
}

int main(){
    vector<string> A = { "abcd", "cdef", "fgh", "de"};

    int i,j,k,m,l;
    n = A.size();
    if(n==1) return A[0].size();
    int rm[n];
    memset(rm,0,sizeof(rm));
    memset(dp,-1,sizeof(dp));
    for(i=0;i<19;i++) for(j=0;j<19;j++) crs[i][j]= INT_MAX; 
    for(i=0; i < n; i++){
        for(j=0; j < n ;j++){
            if(i == j || A[i].size() > A[j].size() ) continue;
            if(A[i] == A[j].substr(0,A[i].size())||
            A[i]== A[j].substr(A[j].size()-A[i].size(),A[i].size())) rm[i] = 1;
        }
    }
    v.resize(0);
    for(i=0;i<n; i++ ) if(rm[i]==0) v.pb(A[i]);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    
    n = v.size();
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++){
            int m = min(v[i].size(),v[j].size());
            
            for(l = m; l >= 0; l--){
            
                if(v[i].substr(v[i].size()-l,l) == v[j].substr(0,l)){
                    crs[i][j] = l;
                    break;
                }
            }
        }
    }
    
    int mn = INT_MAX;
    for(i=0; i<n; i++){
        mn = min(mn, (int)v[i].size() + sol(i,(1<<i) ) );
    }
    cout << mn <<"\n";
    
}
