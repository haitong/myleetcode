/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    void reverseList(ListNode * head, ListNode * end){
        ListNode * start = nullptr, * front = head, * tmp;
        while(start != end){
            tmp = front->next;
            front->next = start;
            start = front;
            front = tmp;
        }
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        
        ListNode * fast = head->next;
        ListNode * slow = head;
        bool middle = true;
        while(fast->next != nullptr){
            fast = fast->next;
            if(fast->next != nullptr){
                fast = fast->next;
            } 
            else{
                middle = false;
                break;
            }
            slow = slow->next;
        }
        
        if(middle) fast = slow->next;
        else fast = slow->next->next;
        
        reverseList(head, slow);
        
        while(slow != nullptr && fast != nullptr){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
