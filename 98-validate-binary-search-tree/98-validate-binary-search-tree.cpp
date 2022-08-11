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
public:
    bool isValidBST(TreeNode* root, long long l = INT_MIN, long long r = INT_MAX) {
        if(root == NULL) return true;
        if(root->val < l || r < root->val) return false;
        return isValidBST(root->left, l, root->val-1LL) && isValidBST(root->right, root->val+1LL, r);
    }
};