def nextPermutation(self, nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    j=-1  #start of reverse sublist, -1 if iteration find permutation is impossible
    for i in range(len(nums)-2,-1,-1):
	# find the one to be swapped with target nums[i] 
        if(nums[i]<nums[i+1]):
            m=len(nums)-1
            while(nums[m]<=nums[i]):
                m-=1
                
            # swap 
            nums[i],nums[m]=nums[m],nums[i]
            j=i
            break
          
    # sorted the rest(reverse sublist,actually)
    j+=1 
    k=len(nums)-1
    while(j<k):
        nums[j],nums[k]=nums[k],nums[j] 
        j+=1
        k-=1

    return nums
