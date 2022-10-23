class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        results = []
        subset = []
        
        def create_subsets(i):
            # base case, we have made decisions for every val in nums
            # so we can simply return the results
            if i >= len(nums):
                results.append(subset[:])
                return
            # recurse using decision tree
            # we can either include nums[i]
            subset.append(nums[i])
            create_subsets(i+1)
            #or we can decide not to include it
            subset.pop()
            create_subsets(i+1)
            
        create_subsets(0)
        return results
                
            
        
        
