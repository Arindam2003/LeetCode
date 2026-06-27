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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)
        {
            return nullptr;
        }
        if(head->next==nullptr)
        {
            return head;
        }

        ListNode *p=new ListNode();
        ListNode* newhead=p;
        ListNode* c=head;
        ListNode *n=head->next; 

        while(c && c->next)
        {
            p->next=n;
            c->next=n->next;
            n->next=c;

            p=c;
            c=p->next;
            if(c)
            {
                n=c->next;
            }
        }
        return newhead->next;
    }
};