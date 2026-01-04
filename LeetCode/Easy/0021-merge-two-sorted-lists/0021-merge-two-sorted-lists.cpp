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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr && list2==nullptr)
        {
            return nullptr;
        }

        if(list1==nullptr && list2!=nullptr)
        {
            return list2;
        }

        if(list1!=nullptr && list2==nullptr)
        {
            return list1;
        }

        ListNode *i=list1;
        ListNode *j=list2;

        ListNode *aH=nullptr;
        ListNode *aT=nullptr;

        while(i!=nullptr && j!=nullptr)
        {
            if(i->val < j->val)
            {
                if(aH==nullptr)
                {
                    aH=i;
                    aT=i;
                }else{
                    aT->next=i;
                    aT=i;
                }
                i=i->next;
            }
            else{
                if(aH==nullptr)
                {
                    aH=j;
                    aT=j;
                }else{
                    aT->next=j;
                    aT=j;
                }
                j=j->next;
            }
        }

        if(i!=nullptr)
        {
            aT->next=i;
        }

        if(j!=nullptr)
        {
            aT->next=j;
        }
        return aH;
    }
};