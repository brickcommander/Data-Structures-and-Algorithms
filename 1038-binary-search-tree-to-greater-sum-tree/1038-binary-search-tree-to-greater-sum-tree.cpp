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
    int sum;
    void go(TreeNode *root) {
        if(root == NULL) return;
        go(root->right);
        sum = root->val = sum + root->val;
        go(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        go(root);
        return root;
    }
};