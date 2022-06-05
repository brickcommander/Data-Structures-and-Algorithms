class Solution {
    int n;
    vector<bool> col, diag, rdiag;
    vector<vector<string>> ans;
    vector<string> curr;
    bool check(int i, int j) {
        if(i<0 or i>=n or j<0 or j>=n or col[j] or diag[i+j] or rdiag[i-j+n])
            return false;
        return true;
    }
    
    void go(int i) {
        if(i==n) {
            ans.push_back(curr);
            return;
        }
        
        for(int j=0; j<n; j++) {
            if(check(i,j)) {
                diag[i+j] = true;
                rdiag[i-j+n] = true;
                col[j] = true;
                curr[i][j] = 'Q';
                go(i+1);
                diag[i+j] = false;
                rdiag[i-j+n] = false;
                col[j] = false;
                curr[i][j] = '.';
            }
        }
        
        return;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        // Initialization
        this->n = n;
        ans.clear();
        curr.clear();
        string str = "";
        for(int i=0; i<n; i++)
            str.push_back('.');
        for(int i=0; i<n; i++)
            curr.push_back(str);
        col = vector<bool> (n, false);
        diag = vector<bool> (2*n, false);
        rdiag = vector<bool> (2*n, false);
        
        go(0);
        return ans;
    }
};