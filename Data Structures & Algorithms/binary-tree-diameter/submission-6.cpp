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
    int dia = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return dia;
    }

    int depth(TreeNode* root) {
        if (!root) return 0;

        int depL = depth(root -> left);
        int depR = depth(root -> right);

        dia = max(dia, depL + depR);
        return 1 + max(depL, depR);
    }
};
