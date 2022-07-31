struct segmentTree {
    vector<int> v;
    segmentTree(int n) : v(4*n+8, 0) {}
    void update(int root, int l, int r, int index, int value) {
        if(l > r || index < l || index > r) return;
        if(l==r) {
            v[root] = value;
            return;
        }
        int m = (l+r) / 2;
        update(root*2, l, m, index, value);
        update(root*2+1, m+1, r, index, value);
        
        v[root] = v[root*2] + v[root*2+1];
    }
    int query(int root, int l, int r, int start, int end) {
        if(l > r || end < l || r < start) return 0;
        if(start <= l && r <= end) {
            return v[root];
        }
        
        int ans = 0;
        
        int m = (l+r) / 2;
        ans += query(root*2, l, m, start, end);
        ans += query(root*2+1, m+1, r, start, end);
        
        return ans;
    }
};

class NumArray {
    int n;
    segmentTree tree;
public:
    NumArray(vector<int>& nums) : tree(nums.size()), n(nums.size()) {
        for(int i=0; i<n; i++) {
            tree.update(1, 1, n, i+1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        tree.update(1, 1, n, index+1, val);
    }
    
    int sumRange(int left, int right) {
        return tree.query(1, 1, n, left+1, right+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */