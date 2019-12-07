/**

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

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
        ListNode* prev= NULL, *curr= head;
        if(!head) return  NULL;
        while(curr)
        {
         //   next = curr->next;
            if(curr->val == val)
            {
                if(curr==head)
                {
                    head = curr->next;

                }
                if(prev)
                {
                    prev->next = curr->next;
                }
                curr = curr->next;

            }
            else
            {
             prev = curr;
            curr = curr->next;
            }

        }
        return head;
    }
};
