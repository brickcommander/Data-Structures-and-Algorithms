class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        n, m = len(grid), len(grid[0])
        
        def dfs(i,j):
            if not (0 <= i < n and 0 <= j < m) or grid[i][j] != 1:
                return 0
            grid[i][j] = 2
            return 1 + dfs(i-1, j) + dfs(i+1, j) + dfs(i, j-1) + dfs(i, j+1)
        
        def is_connected(i,j):
            return i == 0 or any([0 <= x < n and 0 <= y < m and grid[x][y] == 2 for x,y in [(i-1,j), (i+1,j), (i,j-1), (i,j+1)]])
 
        for i,j in hits:
            grid[i][j] -= 1
        
        for i in range(m):
            dfs(0,i)
            
        ans = [0]*len(hits)
        for k in reversed(range(len(hits))):
            i,j = hits[k]
            grid[i][j] += 1
            if grid[i][j] == 1 and is_connected(i,j):
                ans[k] = dfs(i,j)-1
        
        return ans