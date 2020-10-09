/* By Shashank2409 */

#include<bits/stdc++.h>
using namespace std;
int main(){
	string text , pat;
	cin>>text>>pat;
	
	string total = pat + "$" + text;
	int Z[total.size()];
	memset(Z , 0 , sizeof(Z));
	
	int left = 0 , right = 0; 
	for(int pre = 1; pre < total.size(); pre++){
		if(pre > right){
			left = pre , right = pre;
			while(right < total.size() && total[right] == total[right - left])
				right ++;
			Z[pre] = right - left;
			right --;
		}
		else{
			int tempPre = pre - left;
			if(Z[tempPre] + pre -1 < right)
				Z[pre] = Z[tempPre];
			else{
				left = pre;
				while(right < total.size() && total[right] == total[right - left])
					right ++;
				Z[pre] = right - left;
				right --;
			}
		}
	}
	
	cout<<"The pattern is found at -> ";
	for(int i = 0; i < total.size(); i++)
		if(Z[i] == pat.size())
			cout<<i - pat.size() - 1<<" ";
	
}