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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }

    TreeNode* dfs(TreeNode* curr, int t) {
        if (!curr) return NULL;

        curr -> left = dfs(curr -> left, t);
        curr -> right = dfs(curr -> right, t);

        if (curr -> val == t and !curr -> left and !curr -> right) {
            return NULL;
        }

        return curr;
    }
};