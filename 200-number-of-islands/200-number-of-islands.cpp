class Solution {
    int n, m;
    void recur(int i, int j, vector<vector<char>> &grid) {
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]=='0') return;
        
        grid[i][j] = '0';
        recur(i+1, j, grid);
        recur(i-1, j, grid);
        recur(i, j+1, grid);
        recur(i, j-1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int noOfComponents = 0;
        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='1') {
                recur(i, j, grid);
                noOfComponents++;
            }
        }
        
        return noOfComponents;
    }
};