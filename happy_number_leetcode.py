#https://leetcode.com/problems/happy-number/
class Solution:
    def isHappy(self, n: int) -> bool:
        def helper(n):
            rem = 0
            summ = 0
            while(n>0):
                rem = n % 10
                summ += rem ** 2
                n = n // 10
            return summ
        
        happy = False
        if n == 1:
            happy = True
        temp = n
        seen = set()
        while(happy is not True):
            summ = helper(temp)
            if summ == 1:
                happy = True
            else:
                if summ not in seen:
                    seen.add(summ)
                else:
                    return False
            temp = summ
        return happy
        
        
        
