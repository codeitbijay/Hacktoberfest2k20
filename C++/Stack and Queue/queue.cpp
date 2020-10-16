#include<iostream>
#include<queue>
using namespace std;
void display(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"\n";
}
void display1(queue<int> q)
{
    while(q.size()!=0)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"\n";
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<"the size of the queue is "<<q.size()<<"\n";
    display(q);
   
    display1(q);
    


}
