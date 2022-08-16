#define     F           first
#define     S           second
#define     I           insert
#define     ll          long long
#define     pb          push_back
#define     pii         pair<int,int>
#define     vi          vector<int>
#define     vvi         vector<vector<int>>
#define     vpi         vector<pair<int,int>>
#define     vvpi        vector<vector<pair<int,int>>>

class Solution {
    int n;
    ll N = 1e5, IM = 1e12;
    vvpi g, rg;
    vector<ll> dist_src1, dist_src2, dist_dest;
    
    void bfs(int src, vector<ll> &dist, vvpi &g) {
        queue<pair<int,ll>> q; q.push({src, 0});
        dist[src] = 0;
        while(q.size()) {
            auto [u, c] = q.front(); q.pop();
            if(dist[u] < c) continue;
            // dist[u] = c;
            for(pii p: g[u]) {
                int v = p.F;
                int cost = p.S;
                if(dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;
                    q.push({v, dist[v]});
                }
            }
        }
    }
public:
    Solution():g(N), rg(N), dist_src1(N, IM), dist_src2(N, IM), dist_dest(N, IM) {}
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        this->n = n;
        for(auto &v: edges) {
            int x = v[0], y = v[1], w = v[2];
            g[x].pb({y, w});
            rg[y].pb({x, w});
        }
        
        bfs(src1, dist_src1, g);
        bfs(src2, dist_src2, g);
        bfs(dest, dist_dest, rg);
        
        ll mx = 1e12;
        for(int i=0; i<n; i++) {
            mx = min(mx, dist_src1[i] + dist_src2[i] + dist_dest[i]);
        }
        
        return mx == IM ? -1 : mx;
    }
};