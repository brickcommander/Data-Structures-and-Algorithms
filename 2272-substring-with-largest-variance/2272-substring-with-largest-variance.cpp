class Solution {
public:
    int largestVariance(string s) {
        int mx = 0;
        unordered_set<char> unique(begin(s), end(s));
        for(char a : unique)
         for(char b : unique) 
          if(a != b) {
            int variance = 0;
            bool has_b = false, first_b = false;
            for(char ch : s) {
                variance += (ch==a);
                if(ch == b) {
                    has_b = true;
                    if(first_b && variance >= 0)
                        first_b = false;
                    else if(--variance < 0) {
                        variance = -1;
                        first_b = true;
                    }
                }
                if(has_b) mx = max(mx, variance);
            }
          }
        return mx;
    }
};