/*Modification to Kadane's Algorithm to find 
maximum sub array if all the elements in an array is negative*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
	cin>>a[i];
}	
int max,curr,k=0;
max=curr=a[0];
for(int i=1;i<n;i++){
	k=curr+a[i];
	if(a[i]>k){
		curr=a[i];
		}
	else{
		curr=k;
		}
	if(curr>max){
		max=curr;
		}
	}
cout<<"Maximum sub array sum is "<<max;
return 0;
}
