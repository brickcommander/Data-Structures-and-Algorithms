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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* dummy = new ListNode(0, head), *first = dummy, *curr = NULL, *prev = NULL, *tail = NULL;
        
        for(int i=0; i<left-1; i++) {
            first = first->next;
        }
        tail = first->next;
        curr = tail->next;
        prev = tail;
        for(int i=0; i<right-left; i++) {
            first->next = curr;
            tail->next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tail->next;
        }
        
        first = dummy->next;
        delete dummy;
        return first;
    }
};