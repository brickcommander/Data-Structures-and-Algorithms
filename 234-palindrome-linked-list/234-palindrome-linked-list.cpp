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
class Solution {
public:
    // O(n) Time and O(1) Space
    // 
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head, *prev = NULL;
        bool odd = false;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            ListNode* n = slow->next;
            {
                slow->next = prev;
            }
            prev = slow;
            slow = n;
        }
        ListNode *l = NULL, *r = NULL;
        if(fast->next == NULL) odd = true;
        if(odd) {
            l = prev;
            r = slow->next;
        } else {
            r = slow->next;
            slow->next = prev;
            l = slow;
        }
        
        while(l!=NULL && r!=NULL) {
            if(l->val != r->val) return false;
            l = l->next;
            r = r->next;
        }
        
        return l == NULL && r == NULL; 
    }
};