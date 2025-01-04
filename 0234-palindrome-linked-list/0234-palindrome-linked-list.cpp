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
    ListNode* reverseList(ListNode* head) {
        ListNode *f=nullptr;   //preveous
        ListNode *s=head;   //change
        ListNode *t=nullptr;  //hold 

        while(s!=nullptr)
        {
            t=s->next;
            s->next=f;
            f=s;
            s=t;
        }
        return f;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *f=head;
        ListNode *s=head;
        while(f!=nullptr && f->next!=nullptr)
        {
            s=s->next;
            f=f->next->next;
        }
        if(f!=nullptr)
        {
            s=s->next;
        }
        s=reverseList(s);
        f=head;
        while(s!=nullptr)
        {
            if(s->val!=f->val)
            {
                return false;
            }
            f=f->next;
            s=s->next;
        }
        return true;
    }
    
};