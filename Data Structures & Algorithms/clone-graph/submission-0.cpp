/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> oldToNew;
    Node* dfs(Node* node) {
        if (!node) return NULL;

        if (oldToNew.contains(node)) return oldToNew[node];

        Node* deepCopy = new Node(node -> val);
        oldToNew[node] = deepCopy;

        for(auto& x : node -> neighbors) {
            deepCopy -> neighbors.push_back(dfs(x));
        }

        return deepCopy;
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
