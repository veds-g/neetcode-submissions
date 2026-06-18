/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* headCopy) {
        unordered_map<int, Node*> og, latest;
        unordered_map<Node*, int> rev_og;

        Node* dummy = new Node(0), * res = dummy, * head = headCopy;
        int cnt = 0;
        while (head != nullptr) {
            int val = head -> val;
            res -> next = new Node(val);
            res = res -> next;
            og[cnt] =  head;
            latest[cnt] = res;
            head = head -> next;
            cnt++; 
        }

        for (auto& x : og) rev_og[x.second] = x.first;

        head = headCopy;
        res = dummy -> next;
        while(head != nullptr) {
            int val = res -> val;
            Node* temp = head -> random;

            if (temp != nullptr) {
                int idx = rev_og[temp];
                Node* rand = latest[idx];
                res -> random = rand;
            }

            head = head -> next;
            res = res -> next;
        }

        return dummy -> next;
    }
};
