#include<iostream>
#include<string>
using namespace std;
void tarsum(int *a,int i,int n, string s,int cs,int ts)
{
    if(i==n)
    {
        if(cs==ts)
        {
            cout<<s<<"."<<endl;
        }
        return;
    }
    
    tarsum(a,i+1,n, s + to_string(a[i])+", ", cs+a[i], ts);
    tarsum(a,i+1,n,s,cs,ts);
}
int main()
{
    int n;
    cin>>n;
    int ts,a[n];
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
    }
    cin>>ts;
    tarsum(a,0,n,"",0,ts);
    return 0;
}
