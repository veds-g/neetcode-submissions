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
        calcDia(root);
        return dia;
    }

    int calcDia(TreeNode* root) {
        if (root == NULL) return 0;

        int diaL = calcDia(root -> left);
        int diaR = calcDia(root -> right);

        dia = max(dia, diaL + diaR);
        return 1 + max(diaL, diaR);
    }
};
