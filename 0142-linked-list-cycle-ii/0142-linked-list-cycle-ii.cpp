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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr)
        {
            return nullptr;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* p=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
            {
                break;
            }
        }

        if(fast!=slow)
        {
            return nullptr;
        }

        while(p!=slow)
        {
            p=p->next;
            slow=slow->next;
        }

        return p;
    }
};