/**

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ///  approach is fine but Showing TLE
class Solution {
public:
    ListNode* tailNode(ListNode* head)
    {
        if(!head || !head->next)
        {
            return head;
        }
        while(head->next->next)
        {
            head = head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
        {
            return head;
        }

        for(int i=1;i<=k;i++)
        {
            ListNode* tail = tailNode(head);
            ListNode* temp = tail->next;
            temp->next = head;
            head = temp;
            tail->next = NULL;

        }
        return head;
    }
};

/// Better solution - Accepted one
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || k==0)
        {
            return head;
        }
        ListNode* slow = NULL;
        ListNode* fast = head;
        int n = 0;
        while(fast)
        {
            slow = fast;
            fast = fast->next;
            n++;
        }

         k = k%n;
        if(k==0) return head;
        slow->next = head;
        fast = head;
        for(int i=0; i < (n-k);i++)
        {
            slow = slow->next;
            fast = fast->next;

        }
        slow->next = NULL;
        head = fast;
        return head;


    }
};
