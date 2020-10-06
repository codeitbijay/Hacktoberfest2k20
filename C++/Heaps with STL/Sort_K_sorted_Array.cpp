#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int ,vector<int> ,greater<int> > pq;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    for(int i=0;i<=k;i++)
    {
        pq.push(a[i]);
    }
    for(int i=k+1;i<n;i++)
    {
        cout<<pq.top()<<endl;
        pq.pop();
        pq.push(a[i]);
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}
/*
Sample Input
9
3
2
4
1
6
5
7
9
8
3
Sample Output
1
2
3
4
5
6
7
8
9
*/
