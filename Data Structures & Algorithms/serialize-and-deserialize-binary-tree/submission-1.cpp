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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode* root, string& ans) {
        if (!root) {
            ans += "#,";
            return;
        }

        ans += to_string(root -> val) + ",";
        dfs(root -> left, ans);
        dfs(root -> right, ans);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return createTree(data, idx);
    }
    
    TreeNode* createTree(string& data, int& idx) {
        if (idx == data.size()) return NULL;

        int end = data.find(',', idx);
        string token = data.substr(idx, end - idx);
        idx = end + 1;

        if (token == "#") return NULL;
        
        TreeNode* ans = new TreeNode(stoi(token));
        ans -> left = createTree(data, idx);
        ans -> right = createTree(data, idx);

        return ans;
    }
};
