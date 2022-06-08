/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* node;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int sz = 0;
        ListNode* runner = head;
        while(runner != NULL) {
            sz++;
            runner = runner->next;
        }
        node = head;
        return go(0, sz-1);
    }
    
    TreeNode* go(int start, int end) {
        if(start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* left = go(start, mid-1);
        TreeNode* root = new TreeNode(node->val);
        root->left = left;
        node = node->next;
        root->right = go(mid+1, end);
        return root;
    }
    
};