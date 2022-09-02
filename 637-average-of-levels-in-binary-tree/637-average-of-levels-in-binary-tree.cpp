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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int sz = q.size();
            double currAns = 0;
            int cnt = 0;
            while(sz--) {
                TreeNode* f = q.front(); q.pop();
                currAns += f->val;
                cnt++;
                if(f->left)     q.push(f->left);
                if(f->right)    q.push(f->right);
            }
            answer.push_back(currAns / cnt);
        }
        return answer;
    }
};