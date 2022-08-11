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
    pair<int,int> go(TreeNode* root, int &cnt) {
        if(root == NULL) return {0,0};
        
        pair<int,int> curr = {root->val, 1};
        pair<int,int> p;
        
        p = go(root->left, cnt);
        curr.first += p.first, curr.second += p.second;
        
        p = go(root->right, cnt);
        curr.first += p.first, curr.second += p.second;
        
        if(curr.first / curr.second == root->val) cnt++;
        return curr;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        go(root, cnt);
        return cnt;
    }
};