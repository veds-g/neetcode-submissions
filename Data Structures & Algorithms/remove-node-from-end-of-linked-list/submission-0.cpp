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
        ListNode* slow = head, * fast = head, * prev = nullptr;

        for (int i = 0; i < n; i++) {
            fast = fast -> next;
        }

        while (fast != nullptr) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next;
        }

        ListNode* isNextPossible = slow -> next;
        slow -> next = nullptr;

        if (prev == nullptr) return isNextPossible;
        prev -> next = isNextPossible;

        return head;
    }
};
