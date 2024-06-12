#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &A) {
    int l=A.size();
    vector<int> left(l),right(l);
    stack<int> s,s1;
    for(int i=0;i<l;i++){
        while(!s.empty() && A[s.top()]>=A[i]){
            s.pop();
        }
        if(s.empty()) left[i]=-1;
        else left[i]=s.top();
        s.push(i);
    }
    for(int i=l-1;i>=0;i--){
        while(!s1.empty() && A[s1.top()]>=A[i]){
            s1.pop();
        }
        if(s1.empty()) right[i]=-1;
        else right[i]=s1.top();
        s1.push(i);
    }
    int ans=0,ll,rl;
    for(int i=0;i<l;i++){
        if(left[i]==-1) ll=i;
        else ll=abs(left[i]-i)-1;
        if(right[i]==-1) rl=l-1-i;
        else rl=abs(right[i]-i)-1;
        // cout<<"value of ll and rl is "<<ll<<" "<<rl<<endl;
        ans=max(ans,A[i]*(ll+rl+1));
    }
    return ans;
}

int main(){
    vector<int> v={2, 1, 5, 6, 2, 3};
    cout<<largestRectangleArea(v)<<endl;

}

