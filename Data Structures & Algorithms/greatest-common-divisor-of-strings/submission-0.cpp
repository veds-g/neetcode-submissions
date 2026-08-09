class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if (n > m) {
            swap(str1, str2);
            swap(n, m);
        }

        string temp = "", ans = "";
        for(int i = 0; i < n; i++) {
            temp += str1[i];
            int sz = temp.size();
            if (n % sz == 0 and m % sz == 0) {
                string a = "";
                for (int i = 0; i < n / sz; i++) a += temp;
                string b = "";
                for (int i = 0; i < m / sz; i++) b += temp;

                if (a == str1 and b == str2) {
                    ans = temp;
                }
            }
        }

        return ans;
    }
};