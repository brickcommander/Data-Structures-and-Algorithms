class Solution {
    int dp[500][500];
    int go(int i, int j, string &s) {
        if(j <= i) return 0;
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        ans = 1e3;
        if(s[i] == s[j]) ans = go(i+1, j-1, s);
        else ans = min(go(i+1, j, s) , go(i, j-1, s)) + 1;
        
        return ans;
    }
public:
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return go(0, s.size()-1, s);
    }
};