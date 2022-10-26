/*
LINK: https://leetcode.com/problems/wiggle-subsequence/
IDEA: We initialize previous_difference = 0.
      We find the current_difference (nums[i] - nums[i - 1]), if it is opposite in sign to previous_difference, we know that we have come across a peak.
      So, we increase the length of subsequence.
*/
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = 1, pd = 0, cd;
	for(int i = 1; i < nums.size(); i++){
		cd = nums[i] - nums[i - 1];
		if((cd > 0 && pd <= 0) || (cd < 0 && pd >= 0))
			size++, pd = cd;
	}
	return size;
    }
};
