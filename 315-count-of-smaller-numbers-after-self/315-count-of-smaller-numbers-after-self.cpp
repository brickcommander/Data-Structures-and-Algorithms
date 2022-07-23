class segmentTree {
private:
    int offset, last;
    vector<int> v;
public:
    segmentTree() : v(4*2*1e4, 0), offset(1e4+1), last(2*1e4) {};
    void insert(int x) {
        insert(1, 1, last, x+offset);
    }
    int count(int x) {
        return query(1, 1, last, 1, x+offset-1);
    }
private:
    void insert(int p, int low, int high, int val) {
        if(low > high || val < low || high < val) return;
        if(low == high) {
            v[p]++;
            return;
        }
        int mid = (low + high) / 2;
        insert(p*2, low, mid, val);
        insert(p*2+1, mid+1, high, val);
        v[p] = v[p*2] + v[p*2+1];
    }
    int query(int p, int low, int high, int l, int r) {
        if(l > r || high < l || r < low) return 0;
        if(l <= low && high <= r) return v[p];
        int mid = (low + high) / 2;
        return query(p*2, low, mid, l, r) + query(p*2+1, mid+1, high, l, r);
    }
};

class Solution {
    int n;
public:
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        segmentTree TREE;
        vector<int> ans(n, 0);
        for(int i=n-1; i>=0; i--) {
            ans[i] = TREE.count(nums[i]);
            TREE.insert(nums[i]);
        }
        return ans;
    }
};