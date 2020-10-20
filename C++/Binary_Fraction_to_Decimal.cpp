#include<bits/stdc++.h>
using namespace std;

double BinaryToDecimal(string binary,int l){
  size_t point = binary.find('.');
    if (point == string::npos)
        point = l;
    double intDecimal = 0, fracDecimal = 0, two = 1;
    for (int i = point-1; i>=0; --i)
    {
        intDecimal += (binary[i] - '0') * two;
        two *= 2;
    }
    two = 2;
    for (int i = point+1; i < len; ++i)
    {
        fracDecimal += (binary[i] - '0') / two;
        two *= 2.0;
    }
    return intDecimal + fracDecimal;
}

int main()
{
    string n;
    getline(cin,n);
    cout << BinaryToDecimal(n, n.length()) << "\n";
    return 0;
}
  
