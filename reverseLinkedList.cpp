/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode tmp_head(0);
        tmp_head.next = head;
        
        ListNode * curr, * next, *second;
        
        second = NULL;
        
        curr = head;
        
        while(curr != NULL){
            next = curr->next;
            
            curr->next = second;
            second = curr;
            tmp_head.next = curr;
            
            curr = next;
        }
        
        return tmp_head.next;
    }
};

