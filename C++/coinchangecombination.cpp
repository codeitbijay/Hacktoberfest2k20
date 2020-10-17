#include<iostream>
#include<cstring>
using namespace std;

int main(){
   int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int tag =0;
    cin>>tag;
    int t[tag+1];
    memset(t,0,sizeof(t));
    t[0]=1;
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<=tag;j++){
            
                t[j]+=t[j-arr[i]];
            }
            
        }
    
    
    cout<<t[tag];
    return 0;
    
}
