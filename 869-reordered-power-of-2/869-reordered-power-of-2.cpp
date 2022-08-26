class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> v;
        for(int p=1; p<=1e9; p*=2) {
            v.push_back(to_string(p));
        }
        string f = to_string(n);
        sort(f.begin(), f.end());
        for(string str: v) {
            sort(str.begin(), str.end());
            if(str == f) return true;
        }
        return false;        
    }
};