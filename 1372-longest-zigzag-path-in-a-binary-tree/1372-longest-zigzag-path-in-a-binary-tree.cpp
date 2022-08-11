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
    int mx_len;
    pair<int,int> go(TreeNode* root) {
        if(root == NULL) return {0,0};
        pair<int,int> x = go(root->left);
        pair<int,int> y = go(root->right);
        mx_len = max({mx_len, x.second, y.first});
        return {x.second+1, y.first+1};
    }
public:
    int longestZigZag(TreeNode* root) {
        mx_len = 0;
        go(root);
        return mx_len;
    }
};