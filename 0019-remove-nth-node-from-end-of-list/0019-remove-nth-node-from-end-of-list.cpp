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
        ListNode* temp=head;
        int len=0;
        while(temp)
        {
            temp=temp->next;
            len++;
        }

        if(len==n) // delete first node
        {
            return head->next;
        }

        int prev_pos=len-n;
        temp=head;
        for(int i=1;i<prev_pos;i++)
        {
            temp=temp->next;
        }

        temp->next=temp->next->next;
        return head;
    }
};