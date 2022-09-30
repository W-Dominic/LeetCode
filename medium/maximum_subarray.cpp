def maxSubArray(self, nums: List[int]) -> int:
        #Kadane's algorithm
        localmax = 0
        globalmax = 0
        isNegative = True
        
        for num in nums:
            if num > 0:
                isNegative = False
            localmax = max(localmax + num, num)
            if (globalmax < localmax):
                globalmax = localmax
        
        #Kadane's algorithm does not work for an array of all negative numbers
        edgecase = max(nums)
        if (isNegative):
            return edgecase
        
        return globalmax
        
