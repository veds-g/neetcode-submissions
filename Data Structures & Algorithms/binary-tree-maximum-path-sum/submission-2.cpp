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
        
        int left = solve(root -> left);
        int right = solve(root -> right);

        int op1 = root -> val + left + right;
        int op2 = root -> val + left;
        int op3 = root -> val + right;
        int op4 = root -> val;

        int res = max(op2, max(op3, op4));
        int res2 = max(op1, res);
        ans = max(ans, res2);

        return res;
    }
};
