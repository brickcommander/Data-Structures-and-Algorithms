// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++



class Solution{
    vector<vector<bool>> isPalindrome;
    vector<int> dp;
    void helperIsPalindrome(string &str) {
        int n = str.size();
        isPalindrome = vector<vector<bool>>(n, vector<bool>(n, false));
        auto &v = isPalindrome;
        for(int i=0; i<n; i++) v[i][i] = 1;
        for(int i=0; i<n-1; i++) if(str[i] == str[i+1]) v[i][i+1] = 1;
        for(int len=3; len<=n; len++) {
            for(int start = 0; start + len - 1 < n; start++) {
                int end = start + len - 1;
                if(str[start] == str[end] && v[start+1][end-1] == true)
                    v[start][end] = true;
            }
        }
    }
    
    int go(int i, int n, string &str) {
        if(i==n) return 0;
        int &ans = dp[i];
        if(ans != -1) return ans;
        ans = 1e9;
        
        for(int j=i; j<n; j++) {
            if(isPalindrome[i][j]) {
                ans = min(ans, 1 + go(j+1, n, str));
            }
        }
        return ans;
    }
    
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        helperIsPalindrome(str);
        dp = vector<int>(n, -1);
        
        return go(0, n, str)-1;
        
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends