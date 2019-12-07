/**

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /// 4 ms
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        if(!head || !head->next)
        {
            return head;
        }
        ListNode* smaller_head = new ListNode(0);
        ListNode* smaller = smaller_head;
        ListNode* greater_head = new ListNode(0);
        ListNode* greater = greater_head;
        ListNode *temp = head;
        while(temp)
        {
            if(temp->val < x)
            {
               smaller->next = temp;
               smaller = smaller->next;

            }
            else
            {

            greater->next = temp;
            greater = greater->next;
            }
            temp = temp->next;

        }
        greater->next = NULL;
        head = smaller_head->next? smaller_head->next : greater_head->next;
        smaller->next =  greater_head->next;
        return head;

    }
};

///8 ms

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
    ListNode* partition(ListNode* head, int x) {

        if(!head || !head->next)
        {
            return head;
        }

        ListNode* smaller = NULL;
        ListNode* greater = NULL, *joint = NULL;
        ListNode *temp = head;
        while(temp)
        {
            if(temp->val < x)
            {
                if(smaller == NULL)
                {
                    head = temp;
                    smaller = temp;
                }
                else
                {
                    smaller->next = temp;
                     smaller = smaller->next;
                }



            }
            else
            {
               if(greater==NULL)
               {
                   greater = temp;
                   joint = temp;
               }
                else
                {
                    greater->next = temp;
                    greater = greater->next;
                }

            }
            temp = temp->next;

        }
        if(greater ==NULL)
        {
            return head;
        }
        greater->next = NULL;

        if(smaller==NULL)
        {
            head = joint;
        }
        else
        {
            smaller->next = joint;
        }
        return head;


    }
};
