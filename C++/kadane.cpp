#include<bits/stdc++.h>
using namespace std;

int maxSubArray_naive(vector<int>& nums) {
        int sum=nums[0];
        for(int i=0;i<nums.size();i++){
            int res=0;
            for(int j=i;j<nums.size();j++){
                res+=nums[j];
                sum=max(res,sum);
            }
            
        }
        return sum;
}
// Kadane's Algorithm

int maxSubArray_efficient(vector<int>& nums) {
        int max_so_far=nums[0], curr_sum=nums[0];
        for(int i=1;i<nums.size();i++){
            curr_sum=max(nums[i],curr_sum+nums[i]);
            max_so_far = max(max_so_far,curr_sum);
        }
        return max_so_far;
}
int main(){
    vector<int>v={-2, -3, 4, -1, -2, 1, 5, -3};
    cout<<maxSubArray_naive(v)<<endl;
    cout<<maxSubArray_efficient(v)<<endl;
    
}
