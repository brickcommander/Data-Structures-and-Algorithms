class Solution {
public:
    // 2262. Total Appeal of A String
    int appealSum(string s) {
        int ans = 0;
        int n = s.size();
        vector<int> prev(26, -1);
        vector<set<int>> v(26);
        for(int i=0; i<n; i++) {
            int x = s[i] - 'A';
            v[x].insert(i);
        }
        for(int i=0; i<26; i++) v[i].insert(n);
        
        for(int i=0; i<n; i++) {
            int x = s[i] - 'A';
            int l = i - prev[x] - 1, r = *v[x].upper_bound(i) - i - 1;
            ans += l + r + 1 + l * r;
            prev[x] = i;
        }
        
        return ans;
    }
    int uniqueLetterString(string s) {
        return appealSum(s);
    }
};