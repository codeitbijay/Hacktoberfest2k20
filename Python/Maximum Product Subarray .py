def maxProduct(self, nums):
        cumltv_min = [0]*len(nums)
        cumltv_max = [0]*len(nums)
        cumltv_min[0] = cumltv_max[0] = nums[0]
        for i in range(1,len(nums)):
            # compare the minimum of min(cur_val*prev_min, cur_val) and min(cur_val*prev_max, cur_val)
            cumltv_min[i] = min( cumltv_min[i-1]*nums[i] , cumltv_max[i-1]*nums[i], nums[i])
            # compare the maximum of max(cur_val*prev_min, cur_val) and max(cur_val*prev_max, cur_val)
            cumltv_max[i] = max ( cumltv_min[i-1]*nums[i], cumltv_max[i-1]*nums[i], nums[i] )
        return max(cumltv_max)
