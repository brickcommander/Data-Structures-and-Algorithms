class Solution {
    int n;
    vector<vector<bool>> isP;
    vector<int> dp;
    void isP_util(const string &s) {
        for(int i=0; i<n; i++) isP[i][i] = true;
        for(int i=0; i<n-1; i++) if(s[i] == s[i+1]) isP[i][i+1] = true;
        for(int len = 3; len <= n; len++) {
            for(int start = 0, end = len-1; end < n; start++, end++) {
                if(s[start] == s[end] && isP[start+1][end-1])
                    isP[start][end] = true;
            }
        }
    }
public:
    bool checkPartitioning(string s) {
        n = s.size();
        isP = vector<vector<bool>> (n, vector<bool> (n, false));
        isP_util(s);
        for(int i=1; i<n; i++) {
            for(int j=i; j<n-1; j++) {
                if(isP[0][i-1] && isP[i][j] && isP[j+1][n-1])
                    return true;
            }
        }
        return false;
    }
};