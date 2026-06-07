class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int& x : nums) mp[x]++;
        
        int maj = -1, mx = -1;
        
        for (auto& x : mp) 
            if (x.second > mx)
                mx = x.second, maj = x.first;

        return maj;
    }
};