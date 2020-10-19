#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main()
{
    priority_queue<int > pq;
    stack<int > q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        pq.push(no);
    }
    int k;
    cin>>k;
    while(k--)
    {
        q.push(pq.top());
        pq.pop();
    }
    while(!q.empty())
    {
        cout<<q.top()<<endl;
        q.pop();
    }
    return 0;
}
/*
Sample Input
13
12
62
22
15
37
99
11
37
98
67
31
84
99
4
Sample Output
84
98
99
99
*/
