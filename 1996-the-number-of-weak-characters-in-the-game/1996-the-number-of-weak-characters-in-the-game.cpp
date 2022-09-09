class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        map<int, int> mp;
        map<int, vector<int> > mp2;
        
        for(const vector<int> &v: prop) {
            mp[v[1]]++;
            mp2[v[0]].push_back(v[1]);
        }
        
        int weak = 0;
        for(const auto &[x, v]: mp2) {
            for(const int &y: v) {
                mp[y]--;
                if(mp[y] == 0) mp.erase(y);
            }
            for(const int &y: v) {
                if(mp.upper_bound(y) != mp.end()) weak++;
            }
        }
        
        return weak;
    }
};