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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;
        return isSameTree(root, subRoot) || isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and q) return false;
        if (p and !q) return false;
        if (!p and !q) return true;

        return (p -> val == q -> val) and isSameTree(p -> left, q -> left) and isSameTree(p -> right, q -> right);
    }
};
