#include<bits/stdc++.h>
using namespace std;

string DecimalToBinary(int n,int k){
  string binary=" ";
  int integral=n;
  double fractional=n-integral;
  while(integral){
    int rem=integral%2;
    binary.push_back(rem+'0');
    integral/=2;
  }
  reverse(binary.begin(),binary.end());
  binary.push_back('.');
  while(k--){
  fractional*=2;
  int fract_bit=fractional;
  if(fract_bit==1){
    fractional-=fract_bit;
    binary.pushback(1+'0');
  }
  else
    binary.push_back(0+'0');
  }
  return binary;
}

int main(){
  double n; //fraction decimal number n
  cin>>n;
  int k; //up-to k precision
  cin>>k;
  cout<<DecimalToBinary(n,k)<<"\n";
  return 0;
}
