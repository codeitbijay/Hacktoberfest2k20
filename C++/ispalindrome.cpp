/*Created by Nevergiv3up*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
  string a,reverseofa;
  cin>>a;
  reverseofa=a;
  reverse(reverseofa.begin(),reverseofa.end());
  if(a==reverseofa)
  {
    cout<<"Palindrome String\n";
  }
  else
  {
    cout<<"Not a Palindrome String\n";
  }
}
