class Solution {
    
    int find_ans(vector<int> &nums1, vector<int> &nums2) {
        
        int prev_left = nums1[0];
        int prev_middle = nums2[0];
        int prev_right = max(prev_left, prev_middle);
        
        int left, middle, right;
        
        for(int i=1; i<nums1.size(); i++) {
            left = prev_left + nums1[i];
            middle = max(prev_middle, prev_left) + nums2[i];
            right = max(prev_right + nums1[i], middle);
            
            prev_left = left;
            prev_middle = middle;
            prev_right = right;
        }
        
        return max(prev_left, prev_right);
    }
    
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(find_ans(nums1, nums2), find_ans(nums2, nums1));
    }
};