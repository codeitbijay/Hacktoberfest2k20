//Distinct absolute array questions
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
         unordered_set<int> s;
        for (int i = 0 ; i < N; i++)
            s.insert(abs(A[i]));

    return s.size();
    }
}