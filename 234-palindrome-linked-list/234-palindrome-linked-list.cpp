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
    // Approach 2: Recusrion, O(n) Recursion Stack Space and O(1) Time
    bool go(ListNode *head, ListNode* prev, ListNode **r) {
        bool f = (head == prev);
        if(head != prev) f = go(head->next, prev, &(*r));
        if(f && head->val == (*r)->val) {
            (*r) = ((*r)->next);
            return true;
        }
        return false;
    }
    
    bool RecursionApproach(ListNode *head) {
        if(head->next == NULL) return true;
        ListNode *f = head, *s = head, *prev = NULL;
        while(f->next && f->next->next) {
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        if(f->next == NULL) {
            // ODD length
            ListNode *r = s->next;
            return go(head, prev, &r);
        } else {
            ListNode *r = s->next;
            return go(head, s, &r);
        }
    }
public:
    // O(n) Time and O(1) Space
    // Loss of Original Linked List
    bool isPalindrome(ListNode* head) {
        
        return RecursionApproach(head);
        
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