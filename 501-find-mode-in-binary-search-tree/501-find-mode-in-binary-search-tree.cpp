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
    int mx, prev, cnt;
    void inOrder(TreeNode* root) {
        if(root == NULL) return;
        inOrder(root->left);
        
        if(root->val == prev)   cnt++;
        else                    cnt = 1;
        mx = max(mx, cnt);
        prev = root->val;
        
        inOrder(root->right);
    }
    
    void inOrder2(TreeNode* root, vector<int> &ans) {
        if(root == NULL) return;
        inOrder2(root->left, ans);
        
        if(root->val == prev)   cnt++;
        else                    cnt = 1;
        if(cnt == mx) ans.push_back(root->val);
        prev = root->val;
        
        inOrder2(root->right, ans);
    } 
    
    public:
    vector<int> findMode(TreeNode* root) {
        mx = 0, prev = -1, cnt = 0;
        inOrder(root);
        vector<int> ans;
        prev = -1, cnt = 0;
        inOrder2(root, ans);
        return ans;
    }
};