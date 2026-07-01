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
    unordered_map<TreeNode*, vector<int>> mp;
public:
    int rob(TreeNode* root) {
        dfs(root);
        return max(mp[root][0], mp[root][1]);
    }

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root -> left);
        dfs(root -> right);

        int include = root -> val;
        int exclude = 0;
        
        if (root -> left) {
            include += mp[root -> left][1];
            exclude += max(mp[root -> left][0], mp[root -> left][1]);
        } 

        if (root -> right) {
            include += mp[root -> right][1];
            exclude += max(mp[root -> right][0], mp[root -> right][1]);
        }

        mp[root] = {include, exclude};
    }
};