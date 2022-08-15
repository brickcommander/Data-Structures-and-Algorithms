class Solution {
    unordered_map<char, int> map;
public:
    int romanToInt(string s) {
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        
        int ans = 0, n = s.size();
        for(int i=0; i<n; i++) {
            if(i == n-1 || map[s[i+1]] <= map[s[i]]) ans += map[s[i]];
            else {
                ans += map[s[i+1]] - map[s[i]];
                i++;
            }
        }
        
        return ans;
    }
};