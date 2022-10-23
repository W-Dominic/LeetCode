class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        hmap = {"2": ["a","b","c"], 
                "3": ["d","e","f"], 
                "4": ["g","h","i"], 
                "5": ["j","k","l"], 
                "6": ["m","n","o"], 
                "7": ["p","q","r","s"], 
                "8": ["t","u","v"], 
                "9": ["w","x","y","z"]}
        
        if len(digits) == 0: return []
        
        results = []
        
        def recursive_shit(i: int, val: str):
            # base case, we have reached the end of the string
            if i == len(digits):
                results.append(val)
                return
            # recursive calls
            # at each level we append all of the vals in hmap[digits[i]]
            letters = hmap[digits[i]]
            for c in letters:
                val += c
                recursive_shit(i + 1, val)
                val = val[:-1]
        recursive_shit(0, "")
        return results
            
            
        
        
        
        
