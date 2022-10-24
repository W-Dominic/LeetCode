class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        '''
        # brute force (naive)
        subarrays1 = []
        for i in range(len(nums1)):
            for j in range(len(nums1)):
                subarrays1.append(nums1[i:j+1])
       
        
        longest = 0
        for arr in subarrays1:
            if (len(arr) > longest):
                start = 0
                end = len(arr)
                while end <= len(nums2):
                    if arr == nums2[start:end]:
                        # we have found a matching subarray
                        longest = end - start
                        break
                    else: 
                        start += 1
                        end += 1
        return longest
        '''
        # construct dp array
        dp = []
        dp.append([0] + [0 for i in nums1])
        for val in nums2:
            dp.append([0] + [0 for i in nums1])
    
        # traverse dp using r and c
        # rules: 
        # 1) if nums1[c] == nums2[r]
        #       - if yes, dp[r][c] += dp[r-1][c-1]
        # 2) keep track of max
        
        len_1 = len(nums1)
        len_2 = len(nums2)
        
        rows = len(dp)
        cols = len(dp[0])
        max_len = 0
        for r in range(1,rows):
            for c in range(1,cols):
                if nums1[c-1] == nums2[r-1]:
                    dp[r][c] = dp[r-1][c-1] + 1
                    max_len = max(max_len, dp[r][c])
        return max_len
        
                
