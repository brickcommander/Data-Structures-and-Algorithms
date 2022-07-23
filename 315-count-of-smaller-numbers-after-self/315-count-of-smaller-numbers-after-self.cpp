
class Solution {
    int n;
    vector<int> ans;
    
    void merge(vector<pair<int,int>> &ar, int l, int m, int r) {
        vector<pair<int,int>> left, right;
        for(int i=l; i<=m; i++)     left.push_back(ar[i]);
        for(int i=m+1; i<=r; i++)   right.push_back(ar[i]);
        
        int i = 0, j = 0;
        while(i < left.size() && j < right.size()) {
            if(left[i].first < right[j].first)
                ans[left[i].second] += j, ar[l++] = left[i++];
            else
                ar[l++] = right[j++];
        }
        
        while(i < left.size())
            ans[left[i].second] += j, ar[l++] = left[i++];
        while(j < right.size())
            ar[l++] = right[j++];
    }
    
    void merge_sort(vector<pair<int,int>> &ar, int l, int r) {
        if(l >= r) return;
        int m = (l + r) / 2;
        merge_sort(ar, l, m);
        merge_sort(ar, m+1, r);
        merge(ar, l, m, r);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        ans = vector<int>(n, 0);
        
        unordered_map<int,int> mp;
        vector<pair<int,int>> v(n);
        for(int i = n-1; i>=0; i--) {
            v[i] = {nums[i], i};
            ans[i] -= mp[nums[i]];
            mp[nums[i]]++;
        }
        
        merge_sort(v, 0, n-1);
        return ans;
    }
};