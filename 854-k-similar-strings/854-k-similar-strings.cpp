class Solution {
    int n;
    vector<string> getNeighbours(string &curr, string &target) {
        vector<string> v;
        int i = 0;
        while(curr[i] == target[i]) i++;
        for(int j=i+1; j<n; j++) {
            if(target[i] == curr[j]) {
                swap(curr[i], curr[j]);
                v.push_back(curr);
                swap(curr[i], curr[j]);
            }
        }
        return v;
    }
    
public:
    int kSimilarity(string &str, string &target) {
        n = str.size();
        unordered_set<string> seen;
        queue<string> q;
        
        q.push(str);
        seen.insert(str);
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string f = q.front(); q.pop();
                if(f == target) return steps;
                for(string str : getNeighbours(f, target)) {
                    if(seen.find(str) == seen.end()) {
                        seen.insert(str);
                        q.push(str);
                    }
                }
            }
            steps++;
        }
        
        return -1;        
    }
};