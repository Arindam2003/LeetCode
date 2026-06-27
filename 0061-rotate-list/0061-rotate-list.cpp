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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        int len=0;
        ListNode * temp=head;
        while(temp)
        {
            temp=temp->next;
            len++;
        }
        k=k%len;

        if(k==0)
        {
            return head;
        }

        ListNode* f=head;
        ListNode* s=head;

        for(int i=0;i<k;i++)
        {
            f=f->next;
        }

        while(f->next!=nullptr)
        {
            f=f->next;
            s=s->next;
        }
        ListNode* newhead=head;
        newhead=s->next;
        f->next=head;
        s->next=nullptr;

        return newhead;
    }
};