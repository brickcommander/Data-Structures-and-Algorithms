class Solution {
public:
    void go(int n, int x, vector<int> &ans) {
        if(x > n) return;
        ans.push_back(x);
        for(int i=0; i<10; i++) {
            go(n, x*10 + i, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<=9; i++) go(n, i, ans);
        return ans;
    }
};