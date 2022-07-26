class Solution {
    int n, m;
    vector<vector<int>> dp;
    
    int go(int i, int j, int prev, vector<vector<int>> &mat) {
        if(i < 0 || i >= n || j < 0 || j >= m || mat[i][j] <= prev) return 0;
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        
        ans = 0;
        int x = go(i+1, j, mat[i][j], mat);
        int y = go(i-1, j, mat[i][j], mat);
        int z = go(i, j+1, mat[i][j], mat);
        int k = go(i, j-1, mat[i][j], mat);
        return ans = max({x, y, z, k}) + 1;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans, go(i, j, -1, matrix));
            }
        }
        
        return ans;
    }
};