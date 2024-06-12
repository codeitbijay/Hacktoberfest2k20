#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,e,i,j;
vector<vector<int> > g;
vector<int> col;
bool visit[1001];
void greedyColoring()
{
   col[0] = 0;
   for (i=1;i<n;i++)
   col[i] = -1;
   bool unuse[n];
   for (i=0;i<n;i++)
   unuse[i]=0;
   for (i = 1; i < n; i++)
   {
      for (j=0;j<g[i].size();j++)
      if (col[g[i][j]] != -1)
      unuse[col[g[i][j]]] = true;
      int cr;
      for (cr=0;cr<n;cr++)
         if (unuse[cr] == false)
      break;
      col[i] = cr;
      for (j=0;j<g[i].size();j++)
      if (col[g[i][j]] != -1)
      unuse[col[g[i][j]]] = false;
   }
}
int main()
{
   int a,b;
   cout<<"Enter number of vertices and edges respectively:";
   cin>>n>>e;
   cout<<"\n";
   g.resize(n);
   col.resize(n);
   memset(visit,0,sizeof(visit));
   for(i=0;i<e;i++)
   {
      cout<<"\nEnter edge vertices of edge "<<i+1<<" :";
      cin>>a>>b;
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
   }
   greedyColoring();
   for(i=0;i<n;i++)
   {
      cout<<"Vertex "<<i+1<<" is coloured with "<<col[i]+1<<"\n";
   }
}
