class Solution {
    vector<bool> col, diag, rdiag;
    int n;
    bool check(int i, int j) {
        if(i<0 or i>=n or j<0 or j>=n or col[j] or diag[i+j] or rdiag[i-j+n])
            return false;
        return true;
    }
    
    int go(int i) {
        if(i==n) return 1;
        
        int ans = 0;
        for(int j=0; j<n; j++) {
            if(check(i,j)) {
                diag[i+j] = true;
                rdiag[i-j+n] = true;
                col[j] = true;
                ans += go(i+1);
                diag[i+j] = false;
                rdiag[i-j+n] = false;
                col[j] = false;
            }
        }
        
        return ans;
    }
    
public:
    int totalNQueens(int n) {
        col = vector<bool> (n, false);
        diag = vector<bool> (2*n, false);
        rdiag = vector<bool> (2*n, false);
        this->n = n;
        return go(0);                 
    }
};