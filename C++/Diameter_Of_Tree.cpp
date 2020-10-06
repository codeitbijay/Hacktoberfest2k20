#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<vector<int> > adj;
int n;
pair<int,int> bfs(int u){
    vector<int> dis(n,-1);
    queue<int> q;
    dis[u]=0;
    q.push(u);
    while(!q.empty()){
        int v=q.front();    q.pop();
        for(auto k: adj[v]){
            if(dis[k]==-1){
                dis[k]=dis[v]+1;
                q.push(k);
            }
        }
    }
    int mx=0;int node=-1;
    for(int v=0;v<n;v++){
        if(dis[v]>mx){
            mx=dis[v];
            node=v;
        }
    }
    return make_pair(node,mx);
}
int main() {
    // The tree is given as an array A,there is an edge between nodes A[i] and
    // i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.
    vector<int> A = {-1, 0, 0, 0, 3};
    if(A.size()<=1) return 0;
    if(A.size()==2) return 1;
    int i,j,k,m,root=-1;
    n=A.size();
    adj.resize(n);
    for(i=0;i<n;i++){
        if(A[i]!=-1) {adj[i].push_back(A[i]);adj[A[i]].push_back(i);}
        if(A[i]==-1) root=i;
        }
    pair<int,int> p1,p2;
    p2 = bfs(root);
    p1 = bfs(p2.first);
    cout << p1.second<<"\n";;
    
}
