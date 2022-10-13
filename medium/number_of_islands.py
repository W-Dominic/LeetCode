class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        rows, cols = len(grid), len(grid[0])
        visited = set()
        islands = 0
        
        def bfs(r, c):
            q = collections.deque()
            visited.add((r, c))
            q.append((r, c))
        
            while q:
                row, col = q.popleft() # BFS
                # row, col = q.pop() # DFS
                directions = [[1,0], [-1,0], [0,1], [0,-1]]
                
                for dr, dc in directions:
                    curr_r = row + dr
                    curr_c = col + dc
                    if (curr_r in range(rows) and
                        curr_c in range(cols) and
                        grid[curr_r][curr_c] == "1" and 
                        (curr_r , curr_c) not in visited):
                            q.append((curr_r, curr_c))
                            visited.add((curr_r, curr_c))
                
                            
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r, c) not in visited:
                    bfs(r, c)
                    islands += 1
        return islands
            
