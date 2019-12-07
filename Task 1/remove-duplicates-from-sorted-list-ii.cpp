/**

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };


 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL, *curr = head, *temp = NULL;
        int duplicate = 0;
        bool duplicate_left = false;
        while(curr)
        {
            if(curr->next && curr->val== curr->next->val || duplicate_left && curr->val==duplicate)
            {
                duplicate = curr->val;
                duplicate_left = true;
                if(curr==head)
                {
                    temp = head;
                    head = head->next;
                    delete temp;
                    temp = NULL;
                    curr = head;
                    prev = curr;
                }
                else
                {
                    temp = curr;
                    prev->next = curr->next;
                    delete temp;
                    temp = NULL;
                    curr = prev->next;
                }
            }
            else
            {
                duplicate = 0;
                duplicate_left = false;
                prev = curr;
                curr = curr->next;
            }
        }
        return head;

    }
};
