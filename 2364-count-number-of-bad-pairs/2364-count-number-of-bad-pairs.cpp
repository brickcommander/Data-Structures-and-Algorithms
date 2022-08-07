class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            int l = i - mp[i - nums[i]];
            ans += l;
            mp[i - nums[i]]++;
        }
        return ans;
    }
};