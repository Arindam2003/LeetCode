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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int minval=(int)(1e9);
        int index=-1;

        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=nullptr && lists[i]->val<minval)
            {
                minval=lists[i]->val;
                index=i;
            }
        }

        if(index==-1)
        {
            return nullptr;
        }

        ListNode* starting=lists[index];
        lists[index]=lists[index]->next;
        starting->next=mergeKLists(lists);

        return starting;
    }
};