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
    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* i = l1;
        ListNode* j = l2;

        ListNode* answerHead = nullptr;
        ListNode* answerTail = nullptr;

        int carry = 0;
        while (i != nullptr && j != nullptr) {
            int sum = i->val + j->val + carry;
            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);

            if (answerHead == nullptr && answerTail == nullptr) {
                answerHead = newNode;
                answerTail = newNode;
            } else {
                answerTail->next = newNode;
                answerTail = newNode;
            }
            i = i->next;
            j = j->next;
        }

        while (i != nullptr) {
            int sum = i->val + carry;
            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);

            if (answerHead == nullptr && answerTail == nullptr) {
                answerHead = newNode;
                answerTail = newNode;
            } else {
                answerTail->next = newNode;
                answerTail = newNode;
            }
            i = i->next;
        }
        while (j != nullptr) {
            int sum = j->val + carry;
            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);

            if (answerHead == nullptr && answerTail == nullptr) {
                answerHead = newNode;
                answerTail = newNode;
            } else {
                answerTail->next = newNode;
                answerTail = newNode;
            }
            j = j->next;
        }

        if (carry > 0) {
            ListNode* newNode = new ListNode(carry);

            answerTail->next = newNode;
            answerTail = newNode;
        }

        return reverse(answerHead);
    }
};