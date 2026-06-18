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
        if (lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) {
            return a -> val > b -> val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);

        for (auto& x : lists) {
            if (x != NULL) heap.push(x);
        }

        ListNode* res = new ListNode(0);
        ListNode* curr = res;

        while (!heap.empty()) {
            ListNode* temp = heap.top();
            heap.pop();
            curr -> next = temp;
            curr = curr -> next;

            temp = temp -> next;
            if (temp) heap.push(temp);
        }

        return res -> next;
    }
};
