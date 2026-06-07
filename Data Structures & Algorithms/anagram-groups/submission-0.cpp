class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> mp;
        
        for (auto x : strs) {
            string sortedX = x;
            sort(sortedX.begin(), sortedX.end());
            if (mp.contains(sortedX)) mp[sortedX].push_back(x);
            else mp[sortedX] = {x}; 
        }

        for (auto &x : mp) {
            vector<string> temp;
            for (auto &y : x.second)
                temp.push_back(y);
            res.push_back(temp);
        }
        
        return res;
    }
};
