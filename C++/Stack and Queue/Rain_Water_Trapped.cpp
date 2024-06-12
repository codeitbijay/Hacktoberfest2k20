#include<bits/stdc++.h>
using namespace std;


int trap(vector<int> &A) {
    int l=A.size();
    vector<int> left(l),right(l);
    left[0]=A[0];
    for(int i=1;i<l;i++){
        left[i]=max(left[i-1],A[i]);
    }
    right[l-1]=A[l-1];
    for(int i=l-2;i>=0;i--){
        right[i]=max(right[i+1],A[i]);
    }
    int ans=0;
    for(int i=0;i<l;i++){
        ans+=min(left[i],right[i])-A[i];
    }
    return ans;
}


int main(){
    vector<int> v={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<trap(v)<<endl;
}
