class Solution {
    int TicketsUsed, TotalTickets;
    unordered_map<string, multiset<string>> g;
    
    bool dfs(string curr, vector<string> &ans) {
        if(TotalTickets == TicketsUsed) {
            return true;
        }
        if(g.find(curr) == g.end()) return false;
        
        multiset<string> st = g[curr];
        for(string dest : st) {
            
            g[curr].erase(g[curr].find(dest));
            ans.push_back(dest);
            TicketsUsed++;
            
            if(dfs(dest, ans)) return true;
            
            TicketsUsed--;
            ans.pop_back();
            g[curr].insert(dest);
            
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket: tickets) {
            g[ticket[0]].insert(ticket[1]);
        }
        TicketsUsed = 0;
        TotalTickets = tickets.size();
        
        vector<string> ans;
        ans.push_back("JFK");
        
        dfs("JFK", ans);
        
        return ans;
    }
};