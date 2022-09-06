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
    
    bool go(TreeNode *root) {
        if(root == NULL) return false;
        
        if(root->left && !go(root->left)) {
            delete root->left;
            root->left = NULL;
        }
        if(root->right && !go(root->right)) {
            delete root->right;
            root->right = NULL;
        }
        
        return root->left || root->right || root->val == 1;
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root && !go(root)) {
            delete root;
            root = NULL;
        }
        return root;
    }
};