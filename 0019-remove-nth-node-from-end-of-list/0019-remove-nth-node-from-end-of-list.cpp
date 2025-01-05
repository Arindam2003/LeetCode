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
    ListNode *prev = nullptr;  // Previous node
    ListNode *current = head; // Current node
    ListNode *next = nullptr; // Next node (for holding)

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr || (head->next == nullptr && n == 1)) {
        return nullptr;
    }

    ListNode* temp = reverseList(head);

    if (n == 1) {
        temp = temp->next; 
    } else {
        ListNode* current = temp;
        for (int i = 1; i < n - 1; ++i) {
            current = current->next;
        }
        current->next = current->next->next;
    }

    return reverseList(temp);
}

};