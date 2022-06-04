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
    TreeNode* go(TreeNode* root) {        
        if(root->left == NULL and root->right == NULL) return root;
        if(root->left == NULL) return go(root->right);
        if(root->right == NULL) {
            root->right = root->left;
            root->left = NULL;
            return go(root->right);
        }
        
        TreeNode* tl = go(root->left);
        tl->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return go(tl->right);
    }
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        go(root);
    }
};