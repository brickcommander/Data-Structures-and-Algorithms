class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0;
        int n = s.size();
        vector<int> prev(26, -1);
        
        for(int i=0; i<n; i++) {
            int x = s[i] - 'a';
            int l = i - prev[x] - 1, r = n - i - 1;
            ans += l + r + 1 + l * r;
            prev[x] = i;
        }
        
        return ans;
    }
};