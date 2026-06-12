class Solution {
private:
    int getDiff(int x, int k) {
        return abs(x - k);
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        set<int> s;

        int idx = -1, diff = INT_MAX, n = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            int val = getDiff(x, arr[i]);
            if (val < diff) diff = val, idx = i;
        }

        int l = idx - 1, r = idx;
        while (k && (l >= 0 || r < n)) {
            int diff1 = INT_MAX, diff2 = INT_MAX;
            if (l >= 0) diff1 = getDiff(x, arr[l]);
            if (r < n) diff2 = getDiff(x, arr[r]);

            if (diff1 <= diff2) s.insert(l), l--;
            else s.insert(r), r++;
            k--;
        } 

        vector<int> ans;
        for(auto& x : s) ans.push_back(arr[x]);

        return ans;
    }
};