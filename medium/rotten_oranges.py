class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # we can do bfs from the starting rotting oranges
        # keep track of "minutes"
        # once bfs is done we check to see if there are any remaining fresh oranges
        
        rows, cols = len(grid), len(grid[0])
        
        # first find all fresh / rotten oranges
        num_fresh = 0
        rotten = collections.deque()
        for r in range(rows):
            for c in range(cols):
                curr = grid[r][c]
                if (curr == 1): num_fresh += 1
                elif (curr == 2): rotten.append((r, c))
                    
        # edge case:
        if num_fresh == 0: return 0
            
        # bfs 
        directions = [[1,0], [-1,0], [0,1], [0,-1]]

        def bfs(r, c): # returns num_oranges made rotten
            made_rotten = 0
            for dr, dc in directions:
                new_r = dr + r
                new_c = dc + c
                if ( new_r in range(rows) and 
                    new_c in range(cols) and
                    grid[new_r][new_c] == 1 ):
                        grid[new_r][new_c] = 2
                        rotten.append( (new_r, new_c) )
                        made_rotten += 1
            return made_rotten
        
        # next start bfs from each of the rotten oranges
        minutes = -1
        while(rotten):
            for i in range(len(rotten)):
                root = rotten.popleft()
                num_fresh -= bfs(root[0], root[1])
            minutes += 1
            print(minutes)
        
        if (num_fresh > 0): return -1
        return minutes
