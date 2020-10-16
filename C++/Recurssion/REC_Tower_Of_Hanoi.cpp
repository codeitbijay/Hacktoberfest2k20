#include<iostream>
using namespace std;
void tow(int n,int s,int d,int h)
{
    if(n==0)
    {
        return;
    }
    //n-1 from s to h
    tow(n-1,s,h,d);
    cout<<n<<"["<<s<<" -> "<<d<<"]"<<endl;
    //n-1 from h to d
    tow(n-1,h,d,s);
}
int main()
{
    int n,i1,i2,i3;
    cin>>n>>i1>>i2>>i3;
    tow(n,i1,i2,i3);
    return 0;
}
