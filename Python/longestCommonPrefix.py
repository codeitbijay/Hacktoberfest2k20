def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)==0:
            return ""
        pref=strs[0]
        for i in range(1,len(strs)):
            temp=strs[i]
            j=0
            
            while j<len(pref) and j<len(temp):
                if pref[j]==temp[j]:
                    j=j+1
                    continue
                else:
                    break
                
            pref=pref[:j]
        return pref
        
