/**

Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.



Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next))
        {
            return head;
        }

        ListNode* remaining = head->next->next;
        ListNode* newhead = head->next;
        head->next->next = head;
        head->next = swapPairs(remaining);
        return newhead;


    }
};
