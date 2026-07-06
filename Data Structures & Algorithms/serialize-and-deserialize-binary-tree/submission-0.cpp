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
        if (!root) return;

        ans += 'P' + to_string(root -> val);

        ans += 'L';
        if (root -> left) {
            ans += to_string(root -> left -> val);
        }

        ans += 'R';
        if (root -> right) {
            ans += to_string(root -> right -> val);
        }

        dfs(root -> left, ans);
        dfs(root -> right, ans);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return createTree(data, idx);
    }
    
    // P1L2R3P2LRP3L4R5P4LRP5LR
    TreeNode* createTree(string data, int& idx) {
        if (idx == data.size()) return NULL;

        size_t p0Idx = data.find('P', idx);
        size_t p1Idx = data.find('P', idx + 1);
        size_t lIdx = data.find('L', idx);
        size_t rIdx = data.find('R', idx);

        string curr = data.substr(idx, p1Idx - p0Idx);
        string p = curr.substr(1, lIdx - p0Idx - 1);
        string l = curr.substr(lIdx - p0Idx + 1, rIdx - lIdx - 1);
        string r = curr.substr(rIdx - p0Idx + 1, p1Idx - rIdx - 1);

        idx += p1Idx - p0Idx;
        
        TreeNode* ans = new TreeNode(stoi(p));

        if (!l.empty()) {
            ans -> left = createTree(data, idx);
        }

        if (!r.empty()) {
            ans -> right = createTree(data, idx);
        }

        return ans;
    }
};
