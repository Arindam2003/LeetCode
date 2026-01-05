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
        ListNode *nxt=head->next;
        ListNode *aage=head->next->next;

        nxt->next=head;
        head->next=swapPairs(aage);
        return nxt;
    }
};