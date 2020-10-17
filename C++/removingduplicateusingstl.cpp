//removing duplicate character string  
#include <bits/stdc++.h>
using namespace std;
void removeRecuringDigits(string s)
{
  int n = s.length();
  int j = 1;
  int i = 1;
  while(i < n)
  {
    if (s[i] != s[i-1])
    {
      s[j] = s[i];
      j++;
      i++;  
    }
    
    while(s[i] == s[i-1]) 
    {
        i++;
    }
  }
  s.resize(j);
  cout<<s;
}
int main()
{
  string s;
  cout>>"Enter the words or sentence\n";
  cin>>s;
  removeRecuringDigits(s);
}
