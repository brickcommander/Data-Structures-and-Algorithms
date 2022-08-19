class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> end, freq;
        for(int x: nums) freq[x]++;
        for(int x: nums) {
            if(freq[x] == 0) continue;
            {
                int t = min(freq[x], end[x-1]);
                end[x] += t;
                freq[x] -= t; 
            }
            if(freq[x] > 0) {
                int t = min({freq[x], freq[x+1], freq[x+2]});
                if(freq[x] > t) return false;
                freq[x] -= t;
                freq[x+1] -= t;
                freq[x+2] -= t;
                end[x+2] += t;
            }
        }
        return true;
    }
};