class Solution {
    long long binPow(long long x, long long p, long long mod = 1e9+7) {
    if(p == 1LL) return x%mod;
    if(p == 0LL) return 1%mod;
    if(x == 1LL) return 1%mod;

    long long ans = 1;
    while(p>0) {
        if(p%2) {
            ans = (ans * x) % mod;
            p--;
        }
        else {
            x = (x * x) % mod;
            p /= 2;
        }
    }
    return ans;
}
public:
    int numSubseq(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        const int mod = 1e9+7;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            int l = i, r = n-1;
            int A = -1;
            while(l <= r) {
                int m = (l + r) / 2;
                if(nums[i] + nums[m] <= target) {
                    l = m+1;
                    A = m;
                } else {
                    r = m-1;
                }
            }
            if(A == i) ans = (ans + 1) % mod;
            else if(A > i) {
                ans = (ans + binPow(2, A-i)) % mod;
            }
        }
        return ans;
    }
};