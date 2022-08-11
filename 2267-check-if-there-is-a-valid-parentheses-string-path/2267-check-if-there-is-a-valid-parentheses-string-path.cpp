class Solution {
    int n, m;
    int dp[100][100][200];
    
    inline int g(char ch) {
        if(ch == ')') return -1;
        return 1;
    }
    
    bool go(int i, int j, int val, vector<vector<char>> &grid) {
        if(i >= n || j >= m || val + g(grid[i][j]) < 0) return false;
        val += g(grid[i][j]);
        if(i == n-1 && j == m-1) return val == 0;
        
        int &ans = dp[i][j][val];
        if(ans != -1) return ans;
        
        ans = go(i+1, j, val, grid) | go(i, j+1, val, grid);
        return ans;        
    }
    
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                for(int k=0; k<n+m; k++)
                    dp[i][j][k] = -1;
        
        
        return go(0, 0, 0, grid);
    }
};