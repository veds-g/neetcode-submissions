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
int ans = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
    int solve(TreeNode* root) {
        if (!root) return 0;
        
        int left = max(solve(root -> left), 0);
        int right = max(solve(root -> right), 0);

        int currMax = root -> val + left + right;
        
        ans = max(ans, currMax);

        return root -> val + max(left, right);
    }
};
