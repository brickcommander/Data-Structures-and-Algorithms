class Solution {
    vector<int> num;
    vector<int> digi;
    
    int go() {
        
        if(num.size() == 0) return 1;
        
        int ans = 0;
        
        for(int i=0; i<digi.size(); i++) {
            if(digi[i] < num.back()) {
                ans += pow(digi.size(), num.size()-1);
            } else if(digi[i] == num.back()) {
                num.pop_back();
                ans += go();
                break;
            }
        }
        
        return ans;
    }
    
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        while(n) {
            num.push_back(n%10);
            n/=10;
        }
        
        for(string str: digits) {
            digi.push_back(str[0] - '0');
        }
        sort(digi.begin(), digi.end());
        
        int ans = 0;
        for(int i=1; i<num.size(); i++) {
            ans += pow(digi.size(), i);
        }        
        
        return go() + ans;        
    }
};