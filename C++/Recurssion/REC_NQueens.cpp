#include<iostream>
using namespace std;
bool is_saveplace(int cb[][100],int n,int r,int c)
{
    for(int i=r-1,j=c;i>=0;i--)
    {
        if(cb[i][j]==1)
        {
            return false;
        }
    }
    for(int i=r-1,j=c-1;i>=0 and j>=0;i--,j--)
    {
        if(cb[i][j]==1)
        {
            return false;
        }
    }
    for(int i=r-1,j=c+1;i>=0 and j<n;i--,j++)
    {
        if(cb[i][j]==1)
        {
            return false;
        }
    }
    return true;
}
void nqueens(int cb[][100],int n,int r,string s)
{
    if(r==n)
    {
        cout<<s<<"."<<endl;
        return;
    }
    for(int c=0;c<n;c++)
    {
        if(is_saveplace(cb,n,r,c)==true){
            cb[r][c]=1;
            nqueens(cb,n,r+1, s+to_string(r)+"-"+to_string(c)+", ");
            cb[r][c]=0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int cb[100][100]={0};
    nqueens(cb,n,0,"");
    return 0;
}
