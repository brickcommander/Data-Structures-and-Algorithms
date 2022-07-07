class Solution {
    int n;
    vector<vector<int>> costP;
    vector<vector<int>> dp;
    int palin(const string &s, int i, int j) {
        int cnt = 0;
        while(i < j) {
            if(s[i] != s[j]) cnt++;
            i++; j--;
        }
        return cnt;
    }
    void costP_util(const string &s) {
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                costP[i][j] = palin(s, i, j);
            }
        }
    }
    
    int go(int idx, int k) {
        if(idx == n && k == -1) return 0;
        if(idx == n || k == -1) return 1e7;
        int &ans = dp[idx][k];
        if(ans != -1) return ans;
        
        ans = 1e7;
        for(int j=idx; j<n; j++) {
            ans = min(ans, go(j+1, k-1) + costP[idx][j]);
        }
        
        return ans;
    }
    
public:
    int palindromePartition(string s, int k) {
        n = s.size();
        dp = vector<vector<int>> (n, vector<int> (k, -1));
        costP = vector<vector<int>> (n, vector<int> (n, 0));
        costP_util(s);
        return go(0, k-1);        
    }
};