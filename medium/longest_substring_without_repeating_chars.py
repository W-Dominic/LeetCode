class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0: return 0
        
        start = 0
        end = 0
        longest_len = 0
        vals = set()
        while(end < len(s)):
            curr_str = s[start:end+1]
            curr_val = s[end]
            if curr_val in vals:
                #use sliding window
                vals.remove(s[start])
                start += 1
            else: 
                vals.add(curr_val)
                end += 1
                if (len(curr_str) > longest_len): longest_len = len(curr_str)
        return longest_len
               
