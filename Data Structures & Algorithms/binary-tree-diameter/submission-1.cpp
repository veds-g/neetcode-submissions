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

        int diaLeft = diameterOfBinaryTree(root -> left);
        int diaRight = diameterOfBinaryTree(root -> right);
        int diaCurr = height(root -> left) + height(root -> right);
        return max(diaCurr, max(diaLeft, diaRight));
    }

    int height(TreeNode* root) {
        if (!root) return 0;

        return 1 + max(height(root -> left), height(root -> right));
    }
};
