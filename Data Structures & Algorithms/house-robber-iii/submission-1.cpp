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
    int rob(TreeNode* root) {
        auto [include, exclude] = dfs(root);
        return max(include, exclude);
    }

    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto [linclude, lexclude] = dfs(root -> left);
        auto [rinclude, rexclude] = dfs(root -> right);

        int include = root -> val;
        int exclude = 0;
        
        include += lexclude;
        exclude += max(linclude, lexclude);
        
        include += rexclude;
        exclude += max(rinclude, rexclude);

        return {include, exclude};
    }
};