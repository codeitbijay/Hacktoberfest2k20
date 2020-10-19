/*
counts number of pairs in range of (n+k,n-k) in the array
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,k;
  	cin>>n>>k;
  	int arr[n];
  	for(int i=0;i<n;i++)
      	cin>>arr[i];
  	sort(arr,arr+n);
  	int v[n];
  	memset(v,0,sizeof(v));
  	for(int i=0;i<n-1;i++) {
    	int d=arr[i]+k;
      	for(int j=i+1;j<n;j++) {
          	if(arr[j]!=arr[i] && arr[j]<=d) {
            	v[i]=1;
              	break;
            }
          	if(arr[j]>d)
              	break;
        }
    }
  	for(int i=n-1;i>0;i--) {
    	int d=arr[i]-k;
      	if(v[i])
          	continue;
      	for(int j=i-1;j>=0;j--) {
        	if(arr[i]!=arr[j] && arr[j]>=d) {
            	v[i]=1;
              	break;
            }
          	if(arr[j]<d)
              	break;
        }
    }
  	int r=0;
  	for(int i=0;i<n;i++)
      	if(v[i])
          	r++;
  	cout<<r;
}
