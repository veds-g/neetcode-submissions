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
    unordered_map<int, int> mp;
    int idx = 0;
public:
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        for (int i = 0; i < in.size(); i++) mp[in[i]] = i;
        return solve(pr, 0, in.size() - 1);
    }

    TreeNode* solve(vector<int>& pr, int l, int r) {
        if (l > r) return NULL;

        TreeNode* node = new TreeNode(pr[idx++]);
        int split = mp[node -> val];

        node -> left = solve(pr, l, split - 1);
        node -> right = solve(pr, split + 1, r);

        return node;
    }
};
