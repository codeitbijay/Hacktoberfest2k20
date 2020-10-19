class Solution:        
    def countAndSay(self, n: int) -> str:
        if n <= 0:
            return "0"
        elif n == 1:
            return "1"
        
        lastNum = "11"
        for num in range(3,n+1):
            count = 0
            pointer = 0
            result = ""
            for index in range(len(lastNum)):
                if lastNum[index] != lastNum[pointer]:
                    result = result + str(count) + '' + str(lastNum[index-1])
                    pointer = index
                    count = 1
                else:
                    count +=1   
            result = result + str(count) + '' + str(lastNum[-1])
            lastNum = result
        return lastNum
