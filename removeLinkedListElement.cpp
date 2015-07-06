/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        ListNode tmp(-1);
        ListNode * curr, * next, * front;
        front = & tmp;
        curr = head;
        next = head->next;
        
        while(curr != NULL){
            next = curr->next;
            if(curr->val != val){
                front->next = curr;
                front = curr;
            }
            curr->next = NULL;
            curr = next;
        }
        return tmp.next;
    }
};
