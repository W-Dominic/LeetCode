class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        hmap = Counter(arr)
        freqs = list(hmap.values())
        freqs.sort()
        
        size = len(arr)
        goal_length = len(arr) / 2
        counter = 0
        i = len(freqs) - 1 
        while(i >= 0):
            size -= freqs[i]
            counter += 1
            if (size <= goal_length):
                break
            i -= 1
        return counter
