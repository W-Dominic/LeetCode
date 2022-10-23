class Solution:
    def longestPalindrome(self, s: str) -> str:
        if (len(s) == 1):
            return s
        result = ""
        r_len = 0
        
        def expand(start, end, r_len, result):
            while(start in range(len(s)) and 
                  end in range(len(s)) and
                  s[start] == s[end]
                 ):
                new_len = end - start + 1
                if (new_len > r_len):
                    result = s[start:end+1]
                    r_len = new_len
                start -= 1
                end += 1
            return r_len,result
        
        for i in range(len(s)):
            #odd vals
            r_len, result = expand(i,i,r_len,result)
            #even vals
            r_len, result = expand(i,i+1,r_len,result)
        return result
    
        
