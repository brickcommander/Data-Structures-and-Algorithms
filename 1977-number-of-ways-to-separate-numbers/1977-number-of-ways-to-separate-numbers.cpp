class Solution {
    #define ll long long
    int n;
    string s;
    int mod = 1e9+7;
    vector<vector<int>> dp;
    vector<vector<int>> same;
    
    bool compare(int i, int d) {
        int j = i-d;
        int common = same[j][i];
        if(common >= d) return true;
        return s[j+common] < s[i+common];
    }
    
//     int go(int d, int i) { // O(n^3) solution
//         c++;
//         if(i==n) return 1;
//         int &ans = dp[d][i];
//         if(ans != -1) return ans;
//         ans = 0;
//         if(s[i] == '0') return ans;
        
//         if(d > 0 && i+d <= n && compare(i,d)) {
//             ans = go(d, i+d);
//         }
//         while(++d + i <= n) {
//             ans = (ans + go(d, i+d)) % mod;
//         }
//         return ans;
//     }
    
public:
    int numberOfCombinations(string num) {
        if(num[0] == '0') return 0;
        s = num;
        n = num.size();
        dp = vector<vector<int>> (n+1, vector<int>(n+1, -1));
        same = vector<vector<int>> (n+1, vector<int>(n+1, 0));
        
        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(s[i] == s[j]) {
                    same[i][j] = same[i+1][j+1] + 1;
                }
            }
        }

        for(int i=0; i<n; i++) dp[0][i] = 1;
        
        for(int i=1; i<n; i++) {
            if(s[i] == '0') {
                dp[i] = dp[i-1];
                continue;
            }
            for(int j=i; j<n; j++) {
                int len = j-i+1;
                // starting at i and ending at j
                // prev string ended at i-1 having length <= len
                int prevs = i-1-(len-1), count = 0;
                if(prevs < 0) count = dp[i-1][i-1];
                else {
                    count = (dp[i-1][i-1] - dp[prevs][i-1] + mod) % mod;
                    if(compare(i,len)) {
                        int c = ((dp[prevs][i-1] - (prevs>0 ? dp[prevs-1][i-1] : 0)) + mod) % mod;
                        count = (count + c) % mod;
                    }
                }
                dp[i][j] = (dp[i-1][j] + count) % mod;
            }
        }
        
        
        return dp[n-1][n-1];  
    }
};