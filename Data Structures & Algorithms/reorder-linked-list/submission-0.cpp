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
    void reorderList(ListNode* head) {
        ListNode* curr = head -> next;
        int cnt = 0;

        while(curr) {
            cnt++;
            curr = curr -> next;
        }

        int mid = cnt / 2;

        curr = head;

        while (mid--) curr = curr -> next;

        ListNode* prev = curr;
        curr = curr -> next;
        prev -> next = nullptr;

        ListNode* endOfReversed = curr;

        while (curr) {
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        if (endOfReversed) endOfReversed -> next = nullptr;

        ListNode* ans = head;

        mid = (cnt + 1) / 2;

        curr = head -> next;

        while (mid--) {
            ans -> next = prev;
            ans = ans -> next;
            prev = prev -> next;

            ans -> next = curr;
            ans = ans -> next;
            curr = curr -> next;
        }
    }
};
