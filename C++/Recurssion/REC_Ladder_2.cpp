#include <iostream>
using namespace std;
void ladder(int n,string k)
{
    if(n==0)
    {
        cout<<k<<endl;
        return ;
    }
    if(n<0)
    {
        return ;
    }
    ladder(n-1,k+"1");
    ladder(n-2,k+"2");
    ladder(n-3,k+"3");
    return ;
}
int main() 
{
    int n;
    cin>>n;
    ladder(n,"");
    return 0;
}

