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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }

    TreeNode* lca(TreeNode* r, TreeNode* p, TreeNode* q) {
        if (!r) return NULL;

        int currVal = r -> val;
        int pVal = p -> val;
        int qVal = q -> val;
        if (pVal < currVal and qVal < currVal) {
            return lca(r -> left, p, q);
        } else if (pVal > currVal and qVal > currVal) {
            return lca(r -> right, p, q);
        } else {
            return r;
        }
    }
};
