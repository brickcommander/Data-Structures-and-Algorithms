class Solution {
public:
	int maxh(int i,int prev,vector<vector<int>>& cubo,int n,vector<vector<int>>& dp){
		if(i==n) return 0;
		if(dp[i][prev+1]!=-1) return dp[i][prev+1];
		int pick=INT_MIN;
		if(prev==-1 || (cubo[prev][1]<=cubo[i][1] && cubo[prev][2]<=cubo[i][2])){
			pick=cubo[i][2]+maxh(i+1,i,cubo,n,dp);
		}
		int notpick=maxh(i+1,prev,cubo,n,dp);
		return dp[i][prev+1]=max(pick,notpick);
	}

	int maxHeight(vector<vector<int>>& cubo) {
		int n=cubo.size();
		for(auto &i:cubo) sort(i.begin(),i.end());
		sort(cubo.begin(),cubo.end());
		vector<vector<int>> dp(n,vector<int>(n+1,-1));
		return maxh(0,-1,cubo,n,dp);
	}
};