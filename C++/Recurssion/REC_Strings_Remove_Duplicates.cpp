#include<iostream>
using namespace std;
void rem_dupli(char *in,char * out,int i,int j)
{
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout<<out;
		return;
	}
	if(in[i]==in[i+1])
	{
		rem_dupli(in,out,i+1,j);
	}
	else
	{
		out[j]=in[i];
		rem_dupli(in,out,i+1,j+1);
	}
}
int main() 
{
	char in[1000];
    char out[1000];
	cin>>in;
	rem_dupli(in,out,0,0);
	return 0;
}
/*
i/p: aabbbccdeee
o/p: abcde
*/
