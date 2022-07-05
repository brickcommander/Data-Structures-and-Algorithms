class Solution {
public:
    int candy(vector<int>& ar) {
        int n = ar.size();
        if(n==1) return 1;
        vector<int> candy(n, 1);
        
        vector<int> valleys;
        for(int i=0; i<n; i++) {
            if(i == 0 && ar[i] < ar[i+1])
                valleys.push_back(i);
            else if(i == n-1 && ar[i] < ar[i-1])
                valleys.push_back(i);
            else if(i > 0 && i < n-1 && ar[i-1] >= ar[i] && ar[i] <= ar[i+1])
                valleys.push_back(i);
        }
        
        for(int x : valleys) {
            int l = x-1, r = x+1;
            while(l >=0 && ar[l] > ar[l+1]) {
                candy[l] = max(candy[l], candy[l+1]+1);
                l--;
            }
            while(r < n && ar[r] > ar[r-1]) {
                candy[r] = max(candy[r], candy[r-1]+1);
                r++;
            }
        }
        
        int cost = 0;
        for(int x : candy) cost += x;
        return cost;
    }
};