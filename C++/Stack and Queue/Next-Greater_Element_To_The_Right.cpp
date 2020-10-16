#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int >s1,s2;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    s1.push(a[n-1]);
    s2.push(-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!s1.empty() and a[i]>s1.top())
        {
            s1.pop();
        }
        if(s1.empty())
        {
            s2.push(-1);
        }
        else
        {
            s2.push(s1.top());
        }
        s1.push(a[i]);
    }
    while(!s2.empty())
    {
        cout<<s2.top()<<endl;
        s2.pop();
    }
}
/*
Sample Input
5
5
3
8
-2
7
Sample Output
8
8
-1
7
-1
*/
