class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (auto& x : asteroids) {
            ans.push_back(x);

            while (ans.size() > 1) {
                int a = ans.back();
                ans.pop_back();

                int b = ans.back();
                ans.pop_back();

                if (a < 0 && b > 0) {
                    if (abs(a) > abs(b)) ans.push_back(a);
                    else if (abs(b) > abs(a)) ans.push_back(b);
                } else {
                    ans.push_back(b);
                    ans.push_back(a);
                    break;
                }
            }
        }

        return ans;
    }
};