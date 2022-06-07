class Solution {
    vector<vector<int>> dp;
    
    int recur(int n, int i) {
        if(n==0) return 0;
        if(n<0 || i*i > n) return 1e9;
        
        int &ans = dp[n][i];
        if(ans != -1) return ans;
        
        ans = min(recur(n, i+1), recur(n-i*i, i)+1);
        
        return ans;        
    }
    
    int iter(int n) {
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for(int i=1; i*i <= n; i++)
            dp[i*i] = 1;
        
        for(int i=1; i<=n; i++) {
            if(dp[i] == 1e9) continue;
            for(int j=1; ; j++) {
                if(i+j*j>n) break;
                dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
            }
        }
        
        return dp[n];
    }
    
    /*
        This can also be solved with Lagrange's four square theoram,
            which says that, every natrual number is sum of squares of 4 numbers.
            1^2 = 1^2 + 0^2 + 0^2 + 0^2
            5^2 = 4^2 + 3^2 + 0^2 + 0^2
            Proof : 
                (a^2 + b^2 + c^2 + d^2) * (p^2 + q^2 + r^2 + s^2) = (..)^2 + (..)^2 + (..)^2 + (..)^2
                    // Either every number is (multiple of two numbers) or (is a prefect square).
    */
    
public:
    int numSquares(int n) {
        dp = vector<vector<int>>(n+1, vector<int>(sqrt(n)+10, -1));
        return iter(n);
        return recur(n, 1);
    }
};