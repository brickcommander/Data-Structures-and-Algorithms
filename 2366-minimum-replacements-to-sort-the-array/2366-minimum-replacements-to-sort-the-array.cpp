class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int i = nums.size()-1;
        int prev = nums[i--];
        while(i >= 0) {
            int t = (nums[i] + prev - 1) / prev;
            ans += t - 1;
            prev = nums[i] / t;
            i--;
        }
        return ans;
    }
};