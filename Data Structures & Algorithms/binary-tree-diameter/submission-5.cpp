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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int diaL = diameterOfBinaryTree(root -> left);
        int diaR = diameterOfBinaryTree(root -> right);

        int curr = depth(root -> left) + depth(root -> right);
        return max(curr, max(diaL, diaR));
    }

    int depth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(depth(root -> left), depth(root -> right));
    }
};
