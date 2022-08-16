class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26, -1);
        for(int i=0; i<s.size(); i++) {
            int x = s[i] - 'a';
            if(v[x] == -1) v[x] = i;
            else           v[x] = s.size();
        }
        int ans = s.size();
        for(int i=0; i<26; i++) {
            if(v[i] != -1) {
                ans = min(ans, v[i]);
            }
        }
        return ans == s.size() ? -1 : ans;
    }
};