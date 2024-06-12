#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,a,k=0;
		cin>>a>>m;
		while(a--)
		{
			int p,q,r,s;
			cin>>p>>q>>r>>s;
			if(q==r)
			{
				k++;
			}
			if(m%2!=0)
			cout<<"NO"<<"\n";
			else if(k==0)
			cout<<"NO"<<"\n";
			else
			cout<<"YES"<<"\n";
		}
	}
}
