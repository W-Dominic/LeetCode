class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # we can perform a dfs with the following conditions
        # go right if possible
        # else, down
        # else, left
        # else, up
        # 
        # keep track of visited nodes in a set
        rows = len(matrix)
        cols = len(matrix[0])
        
        directions = [[0,1], [1,0], [0,-1], [-1,0]]
        curr_direction = 0 % 4
        visited = set()
        result = []
        
        def dfs(root, curr_direction):
            r = root[0]
            c = root[1]
            
            count = 0
            while(count < 4): 
                dr = directions[curr_direction][0]
                dc = directions[curr_direction][1]
                new_r = dr + r
                new_c = dc + c
                # check if valid
                if (new_r in range(rows) and
                    new_c in range(cols) and 
                    not (new_r, new_c) in visited):
                    visited.add((new_r, new_c))
                    result.append(matrix[new_r][new_c])
                    dfs((new_r, new_c), curr_direction)
                    break
                else:
                    curr_direction = (curr_direction + 1) % 4
                    count += 1
            return
        
        visited.add((0,0))
        result.append(matrix[0][0])
        dfs((0,0), curr_direction)
        return result
        
