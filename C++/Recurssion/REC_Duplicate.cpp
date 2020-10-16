#include<iostream>
using namespace std;
void dupli(char *in, char *out,int i,int j)
{
	if(in[i-1]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
		if(in[i]!=in[i-1])
		{
			out[j]=in[i-1];
			dupli(in,out,i+1,j+1);
		}
		else
		{
			out[j]=in[i-1];
			out[j+1]='*';
			dupli(in ,out,i+1,j+2);
	    }	
}
int main() 
{
	char in[1000];
	cin>>in;
	char out[1000];
	dupli(in,out,1,0);
	return 0;
}
