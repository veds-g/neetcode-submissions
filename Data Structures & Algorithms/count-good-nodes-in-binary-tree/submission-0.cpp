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
    int gn;
public:
    int goodNodes(TreeNode* root) {
        gn = 0;
        dfs(root, root -> val);
        return gn;
    }

    void dfs(TreeNode* r, int mx) {
        if (!r) return;

        if (r -> val >= mx) gn++;
        mx = max(r -> val, mx);

        dfs(r -> left, mx);
        dfs(r -> right, mx);
    }
};
