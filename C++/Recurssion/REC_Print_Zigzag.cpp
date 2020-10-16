#include<iostream>
using namespace std;
void ppz(long int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<" ";
    ppz(n-1);
    cout<<n<<" ";
    ppz(n-1);
    cout<<n<<" ";
}
 int main()
{
   long int n;
    cin>>n;
    ppz(n);
    return 0;
}
