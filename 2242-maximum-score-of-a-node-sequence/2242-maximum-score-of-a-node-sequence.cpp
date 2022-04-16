#define F first
#define S second
#define I insert
class Solution {
    // vector<vector<int>> g;
    int mx = -1, n;
    vector<set<pair<int,int>>> score2;
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        n = scores.size()+1;
        pair<int,int> p = {-1, -1};
        score2 = vector<set<pair<int,int>>> (n);

        for(vector<int> v : edges) {
            int x = v[0], y = v[1];
            int s = scores[x] + scores[y];

            score2[x].I({s,y});
            if(score2[x].size() > 3) score2[x].erase(score2[x].begin());
            
            score2[y].I({s,x});
            if(score2[y].size() > 3)score2[y].erase(score2[y].begin());
        }
        // debug(score2);
        for(vector<int> v : edges) {
            int x = v[0], y = v[1];
            for(auto p1 : score2[x]) {
                for(auto p2 : score2[y]) {
                    set<int> st;
                    st.I(x);
                    st.I(y);
                    st.I(p1.S);
                    st.I(p2.S);
                    if(st.size() == 4 && st.find(-1) == st.end()) {
                        mx = max(mx, p1.F + p2.F);
                    }
                }
            }
        }
        
        // debug(mx);
        return mx;
    }
};