class Solution {
private:
    void merge_sort(vector<int> &nums, int l, int r) {
        if(l >= r) return;
        int m = (l + r) / 2;
        merge_sort(nums, l, m);
        merge_sort(nums, m+1, r);
        
        vector<int> temp;
        int i = l, j = m+1;
        while(i <= m && j <= r) {
            if(nums[i] < nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(j <= r) temp.push_back(nums[j++]);
        while(i <= m) temp.push_back(nums[i++]);
        
        i = 0;
        while(l <= r) {
            nums[l++] = temp[i++];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
};