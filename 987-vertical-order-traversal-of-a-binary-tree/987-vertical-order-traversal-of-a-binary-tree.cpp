/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int gof(TreeNode *root) {
        if(root == NULL) return 0;
        return min(gof(root->left), gof(root->right)) - 1;
    }
    
    void go(TreeNode *root, vector<vector<pair<int,int>>> &answer, int curr, int depth) {
        if(root == NULL)    return;
        
        answer[curr].push_back({depth, root->val});
        go(root->left, answer, curr-1, depth+1);
        go(root->right, answer, curr+1, depth+1);        
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        int leftmost = abs(gof(root));
        vector<vector<pair<int,int>>> A(leftmost+1000);
        
        go(root, A, leftmost, 0);
        
        vector<vector<int>> answer;
        for(auto &v: A) {
            sort(v.begin(), v.end());
            vector<int> curr;
            for(auto &p: v) {
                curr.push_back(p.second);
            }
            if(curr.size()) answer.push_back(curr);
        }
        
        return answer;
    }
};