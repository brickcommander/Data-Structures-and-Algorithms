class Solution {
public:
    int NlogN_Approach(int target, int cur, vector<vector<int>> &s) {

        int i = 0, res;
        priority_queue<int>pq;
        for (res = 0; cur < target; res++) {
            while (i < s.size() && s[i][0] <= cur)
                pq.push(s[i++][1]);
            if (pq.empty()) return -1;
            cur += pq.top(), pq.pop();
        }
        return res;
    }
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        return NlogN_Approach(target, startFuel, stations);
        
        int n = stations.size();
        vector<long> dp(n+1, -1);
        dp[0] = startFuel;
        
        for(int i=0; i<n; i++) {
            for(int j=i; j>=0; j--) {
                if(dp[j] != -1 && dp[j] >= stations[i][0])
                    dp[j+1] = max(dp[j+1], dp[j] + stations[i][1]);
            }
        }
        
        for(int i=0; i<=n; i++) {
            if(dp[i] >= target) return i;
        }
        return -1;
    }
};