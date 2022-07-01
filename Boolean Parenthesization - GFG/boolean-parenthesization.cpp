// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    int n;
    int mod;
    string str;
    vector<vector<vector<int>>> dp;
        
    int go(int i, int j, bool to_make) {
        if(i==j)
            return to_make == (str[i] == 'T' ? true : false);
        
        int &ans = dp[i][j][to_make];
        if(ans != -1) return ans;
        ans = 0;
        
        for(int t=i+1; t<j; t+=2) {
            
            int l_one = go(i, t-1, true);
            int r_one = go(t+1, j, true);
            int l_zero = go(i, t-1, false);
            int r_zero = go(t+1, j, false);
            
            if(to_make) {
                if(str[t] == '^')
                    ans += (l_one * r_zero + l_zero * r_one) % mod;
                if(str[t] == '&')
                    ans += (l_one * r_one) % mod;
                if(str[t] == '|')
                    ans += (l_one * r_one + l_one * r_zero + l_zero * r_one) % mod;
            } else {
                if(str[t] == '^')
                    ans += (l_one * r_one + l_zero * r_zero) % mod;
                if(str[t] == '&')
                    ans += (l_zero * r_zero + l_one * r_zero + l_zero * r_one) % mod;
                if(str[t] == '|')
                    ans += l_zero * r_zero % mod;
            }
        }
        
        return ans % mod;
    }
    
public:
    // Solution() : mod(1003) {}
    int countWays(int N, string S){
        // code here
        n = N;
        str = S;
        mod = 1003;
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2, -1)));
        
        return go(0, n-1, true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends