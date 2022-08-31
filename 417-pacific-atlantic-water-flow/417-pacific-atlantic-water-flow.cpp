class Solution {
    int n, m;
    void dfs(int i, int j, int h, vector<vector<int>> &heights, vector<vector<int>> &mat) {
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j] || heights[i][j] < h) {
            return;
        }
        
        mat[i][j] = 1;
        
        dfs(i+1, j, heights[i][j], heights, mat);
        dfs(i-1, j, heights[i][j], heights, mat);
        dfs(i, j+1, heights[i][j], heights, mat);
        dfs(i, j-1, heights[i][j], heights, mat);

        return;        
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        
        vector<vector<int>> atl(n, vector<int>(m, 0));
        vector<vector<int>> pac(n, vector<int>(m, 0));
        
        for(int row=0; row<n; row++) {
            dfs(row, m-1, 0, heights, atl);
            dfs(row, 0, 0, heights, pac);
        }
        for(int col=0; col<m; col++) {
            dfs(n-1, col, 0, heights, atl);
            dfs(0, col, 0, heights, pac);
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(atl[i][j] && pac[i][j])
                    ans.push_back({i,j});
        
        return ans;        
    }
};