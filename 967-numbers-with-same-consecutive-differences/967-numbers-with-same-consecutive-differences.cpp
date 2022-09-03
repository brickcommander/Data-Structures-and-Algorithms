class Solution {
    void go(int i, int n, int k, string &str, vector<int> &v) {
        if(str.size() == n) {
            v.push_back(stoi(str));
            return;
        }
        
        i = i - k;
        if(i>=0) str.push_back('0'+i), go(i, n, k, str, v), str.pop_back();
        i = i + 2 * k;
        if(i<=9 && i!=(i-2*k)) str.push_back('0'+i), go(i, n, k, str, v), str.pop_back();
        
        return;        
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> v;
        string str = "";
        for(int i=1; i<=9; i++) {
            str.push_back('0'+i);
            go(i, n, k, str, v);
            str.pop_back();
        }
        return v;
    }
};