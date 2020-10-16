#include<bits/stdc++.h>
using namespace std;

//program to reverse a string
string reverse(string x)
{   string k;
	for(string ::reverse_iterator it=x.rbegin();it!=x.rend();it++)
	k.push_back(*it);
	return k;
}
//this is to find the longest palindromic substring
int lpss(string x)
{   int n=x.length();
    int m=n;
    string y=reverse(x);
	int t[n+1][m+1];
	memset(t,0,sizeof(t));
	int result=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x[i-1]==y[j-1])
			{
			t[i][j]=1+t[i-1][j-1];result=max(result,t[i][j]);}
			else
			t[i][j]=0;
		}
	}
	
	cout<<"  i  "<<"\t"<<" j "<<endl;
 cout<<"----|---------------------------"<<endl;
  for(int i=0;i<=n;i++)
  { cout<<"    |";
   for(int j=0;j<=m;j++)
	cout<<t[i][j]<<" ";
    cout<<"\n";
  }
  
  return result;
}
int main()
{
	string x="forgeeksskeegfor";
	cout<<lpss(x);
}
