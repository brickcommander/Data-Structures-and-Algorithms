// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    #define ll long long
    vector<vector<vector<ll>>> dp;
    
    ll go(int i, int j, bool f, int arr[]) {
        if(i>j) return 0;
        ll &ans = dp[f][i][j];
        if(ans != -1) return ans;
        
        if(f) return ans = min(go(i+1, j, !f, arr), go(i, j-1, !f, arr));
        else return ans = max(go(i+1, j, !f, arr) + (ll)arr[i], go(i, j-1, !f, arr) + (ll)arr[j]);
    }
    
    public:
    long long maximumAmount(int arr[], int n){
        // Your code here
        dp = vector<vector<vector<ll>>>(2, vector<vector<ll>>(n, vector<ll>(n, -1)));
        
        return go(0, n-1, 0, arr);
        
    }
};
#undef ll

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends