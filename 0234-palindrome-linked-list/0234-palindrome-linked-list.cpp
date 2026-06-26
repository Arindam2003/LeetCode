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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head; 
        ListNode* slow=head; // middle point 
// find middle point
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
// reverse 2nd part
        ListNode* curr=slow;
        ListNode* prev=nullptr;
        while(curr)
        {   
            ListNode* temp=curr->next;
            curr->next=prev;

            prev=curr;
            curr=temp;
        }
//prev is the last node of this list
        while(prev)
        {
            if(head->val!=prev->val)
            {
                return false;
            }
            prev=prev->next;
            head=head->next;
        }
        return true;


    }
};