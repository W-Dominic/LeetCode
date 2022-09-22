class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # 110101  = 53
        #+  1110  = 14
        #=1000011 = 67
        
        #   111  = 7
        #+  111  = 7
        #= 1110  = 14
        
        # Initialize a string to store the result
        # Variable int power = 0
        # Account for cases
        # 1) 0+0 = store 0, power = 0
        # 2) 0+1 or 0+0 (power = 1) = store 1, power = 0
        # 3) 1+1 = store 0, power = 1
        # 4) 1+1 (power = 1) = store 1, power = 1
        
        # Special Cases:
        # 1) if one of the strings runs out of length, assume 0
        # 2) if both strings run out of length, append if something is left in power
        
        result = ""
        power = '0'
        
        len_a = len(a) - 1 
        len_b = len(b) - 1
        while(len_a >= 0 or len_b >= 0):
            # Special case 1
            if (len_a < 0):
                curr_a = '0'             
            else:
                curr_a = a[len_a]
            if (len_b < 0):
                curr_b = '0'
            else: 
                curr_b = b[len_b]
            
            print("a", curr_a, "b", curr_b, "power", power)
            
            # main cases
            if curr_a == '0' and curr_b == '0' and power == '0':  # case 1
                result = '0' + result    
            elif (curr_a == '0' and curr_b == '1' and power == '0') or (curr_a == '1' and curr_b == '0' and power == '0') or (curr_a == '0' and curr_b == '0' and power == '1'):# case 2 
                result = '1' + result
                power = '0'
            elif (curr_a == '1' and curr_b == '1' and power == '0') or (curr_a == '1' and curr_b == '0' and power == '1') or (curr_a == '0' and curr_b == '1' and power == '1'): # case 3
                result = '0' + result
                power = '1'
            elif curr_a == '1' and curr_b == '1' and power == '1': #case 4
                result = '1' + result
                power = '1'
            
            len_a -= 1
            len_b -= 1
        # Special Case 2
        if power == '1':
            result = '1' + result
        return result
                
                
                
                
        
