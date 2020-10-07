/* By Shashank2409 */

#include<bits/stdc++.h>
using namespace std;
int block;

bool compare(pair<int , int> a , pair<int , int> b){
	if(a.first / block != b.first / block)
		return a.first < b.first;
	return a.second < b.second; 
}

int main(){
	int n , q;
	cin>>n>>q;
	block = sqrt(n);
	long long nos[n];
	for(int i = 0;i < n; i++)
		cin>>nos[i];
	
	pair<int , int> queries[q];
	for(int i = 0; i < q; i++)
		cin>>queries[i].first>>queries[i].second;
	
	sort(queries , queries + q , compare);
		
	int l = 0 , r = 0 , sum = 0;
	for(int i = 0; i < q; i++){
	    
		while(l < queries[i].first){
			sum -= nos[l];
			l++;
		}
		while(l > queries[i].first){
			sum += nos[l - 1];
			l--;
		}
		while(r <= queries[i].second){
			sum += nos[r];
			r++;
		}
		while(r > queries[i].second + 1){
			sum -= nos[r - 1];
			r--;
		}
		cout<<"The sum of numbers from "<<queries[i].first<<" to "<<queries[i].second<<" is "<<sum<<"\n";
	}
}