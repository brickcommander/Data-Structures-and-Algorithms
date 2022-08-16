class Solution {
    vector<vector<int>> dp;
    int go(int i, string &s, int c, int l) {
        if(i >= s.size()) return 0;
        int &ans = dp[i][c];
        if(ans != -1) return ans;
        ans = go(i+1, s, c, l) + (s[i] == '1');
        if(c) ans = min(go(i+l, s, c-1, l), ans);
        return ans;
    }
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        dp = vector<vector<int>>(floor.size(), vector<int>(numCarpets+1, -1));
        return go(0, floor, numCarpets, carpetLen);
    }
};