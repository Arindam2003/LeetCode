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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *prev=NULL;

        while( fast!=NULL && n>0)
        {
            fast=fast->next;
            n--;
        }

        while(fast!=NULL)
        {
            prev=slow;
            fast=fast->next;
            slow=slow->next;
        }

        if(prev==NULL)
        {
            head=head->next;
        }else{
            prev->next=prev->next->next;
        }

        return head;
    }
};