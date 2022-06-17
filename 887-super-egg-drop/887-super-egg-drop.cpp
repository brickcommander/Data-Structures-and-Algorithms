class Solution {
    vector<vector<int>> dp;
    int go(int egg, int floor) {
        
        if(egg == 1) return floor;
        if(floor == 1) return 1;
        if(floor == 0) return 0;
        
        int &ans = dp[egg][floor];
        if(ans != -1) return ans;
        
        ans = 1e9;
        
        int l = 1, h = floor;
        while(l <= h) {
            int m = (l + h) / 2;
            int egg_broke = go(egg-1, m-1);
            int egg_nbroke = go(egg, floor-m);
            
            if(egg_broke < egg_nbroke) l = m+1;
            else                       h = m-1;
            
            ans = min(ans, 1 + max(egg_broke, egg_nbroke));            
        }
        
        return ans;
    }
    
    int iterative(int egg, int floor) {
        for(int j=1; j<=floor; j++)
            dp[1][j] = j;
        for(int i=1; i<=floor; i++)
            dp[i][1] = 1;
        
        for(int e=2; e<=egg; e++)
            for(int k=2; k<=floor; k++) {
                int ans = 1e9;
                for(int j=1, rj=k-1; j<k; j++, rj--)
                    ans = min(ans, 1+max(dp[e-1][j], dp[e][rj]));
            }
        
        return dp[egg][floor];
    }
    
public:
    int superEggDrop(int egg, int floor) {
        dp = vector<vector<int>>(egg+1, vector<int>(floor+1, -1));
        return go(egg, floor);
    }
};