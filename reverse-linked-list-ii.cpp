/**

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || (m==n) || !(head->next))
        {
            return head;
        }
        ListNode* prev = NULL, *curr = head;
        int i=1;
        while(curr)
        {
            if(i==m)
            {
                ListNode* tail = curr;
                ListNode* tempcurr = curr->next;
                ListNode* tempprev = curr;

                while(i<n)
                {
                    ListNode* nextPtr = tempcurr->next;
                    tempcurr->next = tempprev;
                    tempprev = tempcurr;
                    tempcurr = nextPtr;
                    i++;


                }
                if(prev==NULL)
                {
                    head = tempprev;
                }
                else
                {
                    prev->next = tempprev;
                }
                tail->next = tempcurr;

            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
            i++;
        }
        return head;

    }
};
