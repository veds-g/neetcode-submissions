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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* p = NULL, * curr = root;

        while (curr and curr -> val != key) {
            p = curr;
            if (curr -> val < key) curr = curr -> right;
            else curr = curr -> left;
        }

        if (!curr) return root;

        if (!curr -> left || !curr -> right) {
            TreeNode* child = curr -> left ? curr -> left : curr -> right;
            if (!p) {
                return child;
            }
            if (p -> left == curr) {
                p -> left = child;
            } else {
                p -> right = child;
            }
            return root;
        }

        TreeNode* r = curr -> right, * rp = NULL;

        while (r and r -> left) {
            rp = r;
            r = r -> left;
        }

        if (rp) {
            rp -> left = r -> right;
            r -> right = curr -> right;
        }

        r -> left = curr -> left;

        if (p) {
            if (p -> left == curr) p -> left = r;
            else p -> right = r;
            return root;
        }

        return r;
    }
};