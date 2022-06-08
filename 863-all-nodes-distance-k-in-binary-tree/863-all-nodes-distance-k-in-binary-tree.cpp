/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define pb push_back
class Solution {
    vector<int> ans;
    TreeNode* targ;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ans.clear();
        targ = target;
        if(k==0) {
            ans.pb(target->val);
            return ans;
        }
        go(root, k, 0);
        return ans;
    }
    
    //  val == 1 -> ancestor is the traget
    //  val == 2 -> some child is the target
    
    int go(TreeNode* root, int k, int val) { 
        if(root == NULL) return 0;
        if(root == targ) {
            go(root->left, k-1, 1);
            go(root->right, k-1, 1);
            return 1;
        }
        if(val == 1) { // some ancestor is the target
            if(k==0) {
                ans.pb(root->val);
            } else if(k>0) {
                go(root->left, k-1, 1);
                go(root->right, k-1, 1);
            }
            return 0; // doesn't matter
        }
        
        int a = go(root->left, k, 0);
        if(a >= 1) { // root's left subtree has the target at distance a
            if(a == k) ans.pb(root->val);
            if(a < k) {
                go(root->right, k-a-1, 1);
            }
            return a+1;
        }
        
        int b = go(root->right, k, 0);
        if(b >= 1) { // root's right subtree has the target at distance b
            if(b == k) ans.pb(root->val);
            if(b < k) {
                go(root->left, k-b-1, 1);
            }
            return b+1;
        }
        
        return 0;
    }
    
};