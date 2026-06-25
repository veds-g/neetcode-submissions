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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);

        TreeNode* curr = root, * p = NULL;
        int leftOrRight;

        while (curr) {
            p = curr;
            if (val > curr -> val) {
                leftOrRight = 1;
                curr = curr -> right;
            } else {
                leftOrRight = 0;
                curr = curr -> left;
            }
        }

        if (leftOrRight) p -> right = new TreeNode(val);
        else p -> left = new TreeNode(val);

        return root;
    }
};