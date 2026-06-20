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
public:
    bool isBalanced(TreeNode* root) {
        int res = nodes(root);
        if (res == -1) return false;
        return true;
    }

    int nodes(TreeNode* root) {
        if (!root) return 0;
        int l = nodes(root -> left);
        int r = nodes(root -> right);

        if (l == -1 || r == -1) return -1;
        if (abs(l - r) > 1) return -1;
        return 1 + max(l, r);
    }
};
