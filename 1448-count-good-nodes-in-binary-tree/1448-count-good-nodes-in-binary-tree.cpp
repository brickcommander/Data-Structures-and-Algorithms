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
    int go(TreeNode* root, int threshold) {
        if(root == NULL) return 0;
        int ans = 0;
        if(root->val >= threshold) ans = 1, threshold = root->val;
        ans += go(root->left, threshold);
        ans += go(root->right, threshold);
        return ans;
    }
public:
    int goodNodes(TreeNode* root) {
        return go(root, -1e5);
    }
};