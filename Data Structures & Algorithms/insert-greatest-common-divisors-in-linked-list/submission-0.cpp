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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;

        while(curr -> next) {
            ListNode* left = curr;
            ListNode* right = curr -> next;

            int gcd = __gcd(left -> val, right -> val);
            ListNode* gcdN = new ListNode(gcd);

            left -> next = gcdN;
            gcdN -> next = right;
            curr = right;
        }

        return head;
    }
};