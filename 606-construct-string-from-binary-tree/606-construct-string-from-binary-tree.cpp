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
    string serialize(TreeNode* root) {
        string str = "";
        if(root == NULL) return str;
        if(root->right)     str = to_string(root->val) + "(" + serialize(root->left) + ")" + "(" + serialize(root->right) + ")";
        else if(root->left) str = to_string(root->val) + "(" + serialize(root->left) + ")";
        else                str = to_string(root->val);
        return str;
    }
public:
    string tree2str(TreeNode* root) {
        return serialize(root);
    }
};