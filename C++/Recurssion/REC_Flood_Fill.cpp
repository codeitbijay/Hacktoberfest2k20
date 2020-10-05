//flood fill with error
#include<iostream>
#include<cstring>
using namespace std;
void floodfill(int a[][1000],int n,int m,int r,int c,string s, bool visited[10][10])
{
    if(r==n-1 and c==m-1)
    {
        cout<<s<<endl;
        return ;
    }
    if(r<0 or c<0 or r==n or c==m or a[r][c]==1 or visited[r][c]==true)
    {
        return;
    }
    visited[r][c]=true;
    floodfill(a,n,m,r-1,c,s+"t",visited);
    floodfill(a,n,m,r,c-1,s+"l",visited);
    floodfill(a,n,m,r+1,c,s+"d",visited);
    floodfill(a,n,m,r,c+1,s+"r",visited);
    visited[r][c]=false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    bool visited[n][m];
    floodfill(a,n,m,0,0,"",visited);
    
    return 0;
}
