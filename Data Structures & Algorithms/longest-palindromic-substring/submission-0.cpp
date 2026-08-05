class Solution {
private:
    pair<int, int> checkOddPalin(string& s, int idx) {
        int l = idx, r = idx;
        pair<int, int> mxValid = {-1, -1};
        while(l >= 0 and r < s.size()) {
            if (s[l] == s[r]) {
                mxValid = {l, r};
                l--;
                r++;
            } else {
                break;
            }
        }
        return mxValid;
    }

    pair<int, int> checkEvenPalin(string& s, int idx) {
        int l = idx, r = idx + 1;
        pair<int, int> mxValid = {-1, -1};
        while(l >= 0 and r < s.size()) {
            if (s[l] == s[r]) {
                mxValid = {l, r};
                l--;
                r++;
            } else {
                break;
            }
        }
        return mxValid;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int mx = INT_MIN;
        int startIdx = -1;
        for (int i = 0; i < n; i++) {
            // check odd length
            auto [oddL, oddR] = checkOddPalin(s, i);
            // check even length
            auto [evenL, evenR] = checkEvenPalin(s, i);

            if (oddR - oddL + 1 > mx) {
                mx = oddR - oddL + 1;
                startIdx = oddL;
            }

            if (evenR - evenL + 1 > mx) {
                mx = evenR - evenL + 1;
                startIdx = evenL;
            }
        }

        return s.substr(startIdx, mx);
    }
};
