#include<iostream>
using namespace std;
void maze(int n,int m,int i,int j,string out)
{
    if(i>n or j>m)
    {
        return;
    }
    if(i==n and j==m)
    {
        cout<<out<<endl;
        return;
    }
        maze(n,m,i+1,j,out+"v");
        maze(n,m,i,j+1,out+"h");
    
  //  return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    maze(n,m,1,1,"");
}
