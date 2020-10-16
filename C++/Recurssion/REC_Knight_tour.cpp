#include<iostream>
using namespace std;
void display(int a[][10],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void knightTour(int a[][10],int r,int c,int n,int move)
{
    if(r<0 or c<0 or r>=n or c>=n or a[r][c]>0)
    {
        return;
    }
    else if(move==n*n)
    {
        a[r][c]=move;
        display(a,n);
        a[r][c]=0;
        return;
    }
    a[r][c]=move;
    knightTour(a,r-2,c+1,n,move+1);
    knightTour(a,r-1,c+2,n,move+1);
    knightTour(a,r+1,c+2,n,move+1);
    knightTour(a,r+2,c+1,n,move+1);
    knightTour(a,r+2,c-1,n,move+1);
    knightTour(a,r+1,c-2,n,move+1);
    knightTour(a,r-1,c-2,n,move+1);
    knightTour(a,r-2,c-1,n,move+1);
    a[r][c]=0;
}
int main()
{
    int n;
    cin>>n;
    int r,c;
    int a[10][10]={0};
    cin>>r>>c;
    knightTour(a,r,c,n,1);
    return 0;
}
