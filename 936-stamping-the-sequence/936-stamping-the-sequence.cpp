class Solution {
    int n, m;
    string S, T;

    bool canReplace(int i) {
        for(int j=0; j<m; j++) {
            if(T[i+j] == '?' || T[i+j] == S[j]);
            else return false;
        }
        return true;
    }
    void replace(int i) {
        for(int j=0; j<m; j++) {
            T[i+j] = '?';
        }
    }
    
public:
    vector<int> movesToStamp(string stamp, string target) {
        S = stamp, T = target;
        m = S.size(), n = T.size();
        
        vector<bool> vis(n, false);
        vector<int> answer = {};
        
        int moves = 0;
        while(moves < 10*n) {
            
            moves++;
            bool hasChanged = false;
            for(int i=0; i<n-m+1; i++) {
                if(vis[i] == false && canReplace(i)) {
                    replace(i);
                    vis[i] = true;
                    hasChanged = true;
                    answer.push_back(i);
                }
            }
            
            if(count(T.begin(), T.end(), '?') == T.size()){
                break;
            }
            
            if(!hasChanged || moves == 10*n) {
                return {};
            }   
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};