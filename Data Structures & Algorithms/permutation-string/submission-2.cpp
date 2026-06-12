class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int, int> m1, m2;
        int n1 = s1.size(), n2 = s2.size();
        for (auto& x : s1) m1[x - 'a']++;
        
        for (int i = 0; i < n2; i++) {
            char curr = s2[i];
            if (m1.contains(curr - 'a')) {
                if (i + n1 > n2) return false;
                else {
                    string temp = s2.substr(i, n1);
                    for (auto& x : temp) m2[x - 'a']++;
                    if (m1 == m2) return true;
                    m2.clear();
                }                
            }
        }

        return false; 
    }
};
