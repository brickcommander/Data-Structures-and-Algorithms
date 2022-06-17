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
public:
    int superEggDrop(int egg, int floor) {
        dp = vector<vector<int>>(egg+1, vector<int>(floor+1, -1));
        return go(egg, floor);
    }
};