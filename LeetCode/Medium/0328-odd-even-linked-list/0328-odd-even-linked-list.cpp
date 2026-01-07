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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oH = nullptr;
        ListNode* oT = nullptr;

        ListNode* eH = nullptr;
        ListNode* eT = nullptr;

        ListNode* temp = head;

        if(temp==nullptr)
        {
            return temp;
        }

        int index = 1;
        while (temp != nullptr) {
            // even
            if (index % 2 == 0) {
                if (eH == nullptr && eT == nullptr) {
                    eH = temp;
                    eT = temp;
                } else {
                    eT->next = temp;
                    eT = temp;
                }
            } else // odd
            {

                if (oH == nullptr && oT == nullptr) {
                    oH = temp;
                    oT = temp;
                } else {
                    oT->next = temp;
                    oT = temp;
                }
            }

            index++;
            temp = temp->next;
        }

        oT->next = eH;

        if (eT != nullptr) {
            eT->next = nullptr;
        }
        return oH;
    }
};