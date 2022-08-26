class Solution {
public:
    // Approach1: Counter Method
    // Approach2: Two Pointer Method
    bool canConstruct(string to, string from) {
        sort(from.begin(), from.end());
        sort(to.begin(), to.end());
        
        int i = 0, j = 0;
        while(i < from.size() && j < to.size()) {
            if(from[i] == to[j]) {
                i++; j++;
            } else {
                i++;
            }
        }
    
        return j == to.size();
    }
};