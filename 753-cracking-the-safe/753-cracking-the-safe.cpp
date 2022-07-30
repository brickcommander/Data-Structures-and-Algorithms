class Solution {
    int n, k, total;
    unordered_set<string> vis;
    string ans;
    
    bool go(string &str) {
        if(vis.size() == total) {
            ans = str;
            return true;
        }
        // cout << str.size() << " - " << str << " - " << vis.size() << "\n";
        
        string curr = str.substr(str.size()-n+1);
        for(int i=0; i<k; i++) {
            str.push_back('0'+i);
            curr.push_back('0'+i);
            
            if(vis.find(curr) == vis.end()) {
                vis.insert(curr);
                if(go(str)) return true;
                vis.erase(curr);
            }
            
            curr.pop_back();
            str.pop_back();
        }
        return false;
    }
public:
    string crackSafe(int n, int k) {
        this->n = n;
        this->k = k;
        total = pow(k, n);
        string s = "";
        for(int i=0; i<n; i++)  s.push_back('0');
        vis.insert(s);
        go(s);
        return ans;
    }
};