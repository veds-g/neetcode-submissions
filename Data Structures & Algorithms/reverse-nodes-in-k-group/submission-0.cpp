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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = new ListNode(0);
        ListNode* dummy = res;
        ListNode* prev = NULL, * l = head, * r = head;

        while (r) {
            for (int i = 1; i < k; i++) {
                if (r) r = r -> next;
            }
            
            if (r == NULL) break;

            ListNode* temp = r -> next;
            r -> next = NULL;
            ListNode* curr = l;

            while(curr) {
                ListNode* tmp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = tmp;
            }

            dummy -> next = prev;
            dummy = l;
            l = r = temp;
            prev = NULL;
        }

       if (l != r) dummy -> next = l;

        return res -> next;
    }
};
