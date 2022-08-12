class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> ans(persons.size());
        vector<pair<int,int>> v;
        
        for(auto a : flowers) {
            v.push_back({a[0], 1});
            v.push_back({a[1]+1, -1});
        }
        sort(v.begin(), v.end());
        
        vector<pair<int,int>> p;
        for(int i=0; i<persons.size(); i++)
            p.push_back({persons[i], i});
        sort(p.begin(), p.end());
        
        int j = 0, cnt = 0;
        for(auto [person, idx] : p) {
            while(j < v.size() && v[j].first <= person) {
                cnt += v[j].second;
                j++;
            }
            ans[idx] = cnt;
        }
        
        return ans;
    }
};