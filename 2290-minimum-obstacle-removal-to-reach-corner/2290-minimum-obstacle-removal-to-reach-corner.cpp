class Solution {
    vector<int> dir = {1, 0, -1, 0, 1};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        
        set<vector<int>> st;
        st.insert({0, 0, 0});
        
        while(st.size()) {
            vector<int> f = *st.begin();
            st.erase(st.begin());
            int cost = f[0];
            int i = f[1], j = f[2];
            if(i == n-1 && j == m-1) return cost;
            if(dp[i][j] < cost) continue;
            
            for(int k = 0; k < 4; k++) {
                int X = i + dir[k];
                int Y = j + dir[k+1];
                if(X >= 0 && Y >= 0 && X < n && Y < m && dp[X][Y] > cost + grid[X][Y]) {
                    dp[X][Y] = cost + grid[X][Y];
                    st.insert({dp[X][Y], X, Y});
                }
            }            
        }
        
        return -1;
    }
};