#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<pair<string,string>>vec;
	vector<string>txt1;
	vector<string>txt2;
	int size;
	string s;
	cin>>size;
	
	for(int i=0;i<size;i++)
	{cin>>s;txt1.push_back(s);}
	for(int i=0;i<size;i++)
	{cin>>s;txt2.push_back(s);}
	
	
	int i=0;
	int j=0;
	while(i<txt1.size()&&j<txt2.size())
	{
		if(txt1[i]!=txt2[j])
		vec.push_back({txt1[i],txt2[j]});
		i++;j++;
	}
//	if(i==txt1.size()) 		vec.push_back(make_pair("NULL",txt2[j]));
//	else if(j==txt2.size())		vec.push_back(make_pair(txt1[i],"NULL"));
	
	for(auto &x:vec)
	cout<<x.first<<"||"<<x.second<<endl;
	return 0;
}
