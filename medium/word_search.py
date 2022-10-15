class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])
        visited = set()
        
        def dfs(r, c, i):
            if i == len(word):
                return True
            if (r in range(rows) and
                c in range(cols) and
                word[i] == board[r][c] and
                not (r, c) in visited):
                visited.add( (r, c) )
                result = ( dfs(r + 1, c, i + 1) or
                           dfs(r - 1, c, i + 1) or
                           dfs(r, c + 1, i + 1) or
                           dfs(r, c - 1, i + 1) )
                visited.remove( (r, c) )
                return result
            return False
        
        # Optimize
        chrs = set()
        for r in range(rows):
            for c in range(cols):
                tmp = board[r][c]
                if (not tmp in chrs):
                    chrs.add(tmp)
        for c in word:
            if (not c in chrs): return False
        
        
        # Find Targets 
        for r in range(rows):
            for c in range(cols):
                if dfs(r, c, 0): return True
        return False
        
                    
                
        
        
