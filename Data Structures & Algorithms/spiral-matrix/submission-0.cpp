class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ans;
        int top = 0, bot = m.size() - 1;
        int left = 0, right = m[0].size() - 1;

        while (top <= bot && left <= right) {
            // go right
            for (int j = left; j <= right; j++) ans.push_back(m[top][j]);
            top++;

            // go down
            for (int i = top; i <= bot; i++) ans.push_back(m[i][right]);
            right--;

            // go left
            if (top <= bot)
                for (int j = right; j >= left; j--) ans.push_back(m[bot][j]);
            bot--;

            // go up
            if (left <= right)
                for (int i = bot; i >= top; i--) ans.push_back(m[i][left]);
            left++;
        }

        return ans;
    }
};