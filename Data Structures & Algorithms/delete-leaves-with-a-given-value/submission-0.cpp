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
        TreeNode* par = NULL, * curr = root;
        dfs(par, curr, target);
        if (root -> val == target and !root -> left and !root -> right) return NULL;
        return root;
    }

    void dfs(TreeNode* par, TreeNode* curr, int t) {
        if (!curr) return;

        dfs(curr, curr -> left, t);
        dfs(curr, curr -> right, t);

        if (!par) return;

        if (curr -> val == t and !curr -> left and !curr -> right) {
            if (par -> left == curr) par -> left = NULL;
            else par -> right = NULL;
        }
    }
};