class Solution { 
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int n = A.size();
        int answer = 0;
        const int mod = 1e9 + 7;
        sort(A.begin(), A.end());
        unordered_map<int, long long> dp;
        for(int i=0; i<n; i++) {
            int par = A[i];
            dp[par] = 1;
            for(int j=0; j<i; j++) {
                if(par % A[j] == 0) {
                    int child_left = A[j];
                    int child_right = par/A[j];
                    dp[par] = (dp[par] + dp[child_left] * dp[child_right] % mod) % mod;
                }
            }
            answer = (answer + dp[par]) % mod;
        }
        return answer;
    }
};