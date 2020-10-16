#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main()
{
    string str;
    cin>>str;
    stack<int> s;
    int n=1;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch=='d')
        {
            s.push(n);
            n++;
        }
        else
        {
            s.push(n);
            n++;
            while(!s.empty())
            {
                cout<<s.top();
                s.pop();
            }
        }
    }
    s.push(n);
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}
/*
Smallest Number Following Pattern

Question
1. You are given a pattern of upto 8 length containing characters 'i' and 'd'.
2. 'd' stands for decreasing and 'i' stands for increasing
3. You have to print the smallest number, using the digits 1 to 9 only without repetition, such that 
the digit decreases following a d and increases follwing an i.

e.g.
d -> 21
i -> 12
ddd -> 4321
iii -> 1234
dddiddd -> 43218765
iiddd -> 126543

i/p
dddiidid
o/p
432157698
*/
