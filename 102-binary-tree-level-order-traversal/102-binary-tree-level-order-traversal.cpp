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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == NULL) return answer;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            vector<int> curr;
            int sz = q.size();
            while(sz--) {
                TreeNode* f = q.front();
                q.pop();
                curr.push_back(f->val);
                if(f->left)     q.push(f->left);
                if(f->right)    q.push(f->right);
            }
            answer.push_back(curr);
        }
        return answer;
    }
};