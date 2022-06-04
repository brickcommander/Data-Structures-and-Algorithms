class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n, m = len(t), len(s)
        dp = [[0]*(m+1) for i in range(n+1)]
        
        for j in range(m):
            dp[0][j] = 1;
        
        for i in range(1,n+1):
            for j in range(1,m+1):
                dp[i][j] = dp[i][j-1]
                if t[i-1] == s[j-1]:
                    dp[i][j] += dp[i-1][j-1]
        
        return dp[n][m]
        
        