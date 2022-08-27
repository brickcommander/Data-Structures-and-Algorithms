class Solution {
public:
    // Time O(N*N*N*logN), Space O(N)
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mx = -1e9;
        
        for(int i=0; i<m; i++) {
            vector<int> v(n, 0);            
            
            for(int j=i; j<m; j++) {
                for(int t=0; t<n; t++) {
                    v[t] += matrix[t][j];
                }
                
                set<int> st; st.insert(0);
                int sum = 0;
                for(int t=0; t<n; t++) {
                    sum += v[t];
                    auto it = st.lower_bound(sum - k);
                    if(it != st.end()) {
                        mx = max(mx, sum - *it);
                    }
                    st.insert(sum);
                }
            }
        }
        
        return mx;
    }
};