class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> idx(n);
        int ans = 0;
        for(int i=0; i<n; i++) {
            idx[row[i]] = i;
        }
        
        for(int i=0; i<n; i+=2) {
            if(row[i]/2 == row[i+1]/2) continue;
            int missing = row[i] + (row[i]%2 ? -1 : 1);\
            int temp = row[i+1];
            swap(row[i+1], row[idx[missing]]);
            swap(idx[row[i+1]], idx[temp]);
            ans++;
        }
        
        return ans;
    }
};