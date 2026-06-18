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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL, * prevLoop = NULL, * l = head, * r = head;

        for (int i = 1; i < left; i++) prev = l, l = l -> next, r = r -> next;
        for (int i = left; i <= right; i++) r = r -> next;

        ListNode* curr = l;
        while (curr != r) {
            ListNode* temp = curr -> next;
            curr -> next = prevLoop;
            prevLoop = curr;
            curr = temp;
        }

        l -> next = r;
        if (prev) prev -> next = prevLoop;
        else return prevLoop;

        return head;
    }
};