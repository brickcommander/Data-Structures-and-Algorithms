class Solution {
    int n;
    const int mod = 1e9 + 7;
    vector<vector<int>> v;
public:
    int numWays(vector<string>& words, string target) {
        n = words[0].size();
        v = vector<vector<int>>(n, vector<int>(26, 0));
        for(const string &word: words) {
            for(int i=0; i<n; i++) {
                v[i][word[i] - 'a']++;
            }
        }
        
        vector<int> dp(n, 0);
        for(int j=0; j<n; j++) {
            dp[j] = (j>0 ? dp[j-1] : 0) + v[j][target[0]-'a'];
        }
        for(int i=1; i<target.size(); i++) {
            int x = target[i] - 'a';
            vector<int> dp2(n, 0);
            for(int j=1; j<n; j++) {
                dp2[j] = (dp2[j-1] + 1LL * dp[j-1] * v[j][x] % mod) % mod;
            }
            dp = dp2;
        }
        
        return dp[n-1];
    }
};