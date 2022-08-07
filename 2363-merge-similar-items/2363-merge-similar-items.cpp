class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        int i = items1.size()-1, j = items2.size()-1;
        sort(items1.begin(), items1.end());
        sort(items2.begin(), items2.end());
        
        while(i >= 0 && j >= 0) {
            if(items1[i][0] > items2[j][0])
                ans.push_back(items1[i--]);
            else if(items2[j][0] > items1[i][0])
                ans.push_back(items2[j--]);
            else
                ans.push_back({items1[i][0], items1[i--][1] + items2[j--][1]});
        }
        
        while(i >= 0) {
            ans.push_back(items1[i--]);
        }
        while(j >= 0) {
            ans.push_back(items2[j--]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};