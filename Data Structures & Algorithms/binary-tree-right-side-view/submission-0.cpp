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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }

    void dfs(TreeNode* root, int h, vector<int>& ans) {
        if (!root) return;
        if (ans.size() < (h + 1)) ans.push_back(root -> val);
        ans[h] = root -> val;
        dfs(root -> left, h + 1, ans);
        dfs(root -> right, h + 1, ans);
    }
};
