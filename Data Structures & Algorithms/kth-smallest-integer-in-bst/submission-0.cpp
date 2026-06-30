/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    priority_queue<int> pq;
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return pq.top();
    }

    void dfs(TreeNode* r, int k) {
        if (!r) return;

        pq.push(r -> val);
        if (pq.size() > k) pq.pop();

        dfs(r -> left, k);
        dfs(r -> right, k);
    }
};
