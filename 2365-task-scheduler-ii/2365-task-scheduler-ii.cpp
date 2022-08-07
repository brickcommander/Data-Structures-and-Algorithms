class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        int n = tasks.size();
        long long curr_day = 0;
        
        map<int, long long> mp;
        for(int x: tasks) {
            if(mp.find(x) != mp.end()) {
                curr_day = max(curr_day, 1LL * mp[x]);
            }
            curr_day++;
            mp[x] = curr_day + space;
        }
        
        return curr_day;
    }
};