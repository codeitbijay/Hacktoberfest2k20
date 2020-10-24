#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
	int n, i, t, m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%4==0)
			m=n/4;
		else
			m=n/4+1;
		for(i=0;i<n-m;i++)
			cout<<"9";
		for(i=0;i<m;i++)
			cout<<"8";
		cout<<endl;
	}
	return 0;
}
