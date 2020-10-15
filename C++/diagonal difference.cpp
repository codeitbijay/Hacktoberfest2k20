#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ll long long 
#define testcase long long t; cin>>t;
int main()
{
	int n,sum1=0,sum2=0;
    cin>>n;
    int a[n][n];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            sum1 += a[i][j];
            if(j==n-1-i)
            sum2 += a[i][j];
            
            
        }
    }
   	cout<<sum1<<endl<<sum2;
    
    return 0;
    

}

