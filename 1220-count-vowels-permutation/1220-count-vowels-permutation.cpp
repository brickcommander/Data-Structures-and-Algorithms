class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> v(5);
        v[0] = {1};
        v[1] = {0, 2};
        v[2] = {0, 1, 3, 4};
        v[3] = {2, 4};
        v[4] = {0};
        
        const int mod = 1e9+7;
        vector<vector<int>> dp(5, vector<int>(n+1, 0));
        dp[0][1] = dp[1][1] = dp[2][1] = dp[3][1] = dp[4][1] = 1;
        for(int i=1; i<n; i++) {
            for(int j=0; j<5; j++) {
                for(int k: v[j]) {
                    dp[k][i+1] = (dp[k][i+1] + dp[j][i]) % mod;
                }
            }
        }
        
        return (0LL + dp[0][n] + dp[1][n] + dp[2][n] + dp[3][n] + dp[4][n]) % mod;
    }
};