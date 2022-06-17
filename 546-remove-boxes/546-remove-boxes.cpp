class Solution {
    vector<vector<vector<int>>> dp;
    int go(int l, int r, int k, vector<int> &boxes) {
        if (l == r) return (k+1)*(k+1);
        if (l > r) return 0;
        
        int &ans = dp[l][r][k];
        if(ans != -1) return ans;
        
        if(boxes[l] == boxes[l+1]) return ans = go(l+1, r, k+1, boxes);
        
        ans = (k+1)*(k+1) + go(l+1, r, 0, boxes);
        
        for(int j=l+1; j<=r; j++) {
            if(boxes[j] == boxes[l])
                ans = max(ans, go(l+1, j-1, 0, boxes) + go(j, r, k+1, boxes));
        }
        
        return ans;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        dp = vector<vector<vector<int>>>(101, vector<vector<int>> (101, vector<int>(101, -1)));
        return go(0, boxes.size()-1, 0, boxes);
    }
};