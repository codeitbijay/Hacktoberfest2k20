#include<iostream>
#include<stack>
using namespace std;
int main()
{
    long int n;
    cin>>n;
    long int a[n],b[n];
    for(long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    stack<long int> s;
    b[0]=1;
    s.push(0);
    for(long int i=1;i<n;i++)
    {
        while(!s.empty() and a[i]>a[s.top()])
        {
            s.pop();
        }
        if(s.empty())
        {
            b[i]=i+1;
        }
        else
        {
            b[i]=i-s.top();
        }
        s.push(i);
    }
    for(long int i=0;i<n;i++)
    {
        cout<<b[i]<<endl;
    }
}
/*
9
3
2
9
5
4
7
3
1
5
o/p
1
1
3
1
1
3
1
1
3
*/
