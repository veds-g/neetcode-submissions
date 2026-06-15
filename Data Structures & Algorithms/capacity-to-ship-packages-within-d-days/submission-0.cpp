class Solution {
private:
bool canShip(const vector<int>& weights, int days, int cap) {
    int ships = 1, currCap = cap;
    for (int w : weights) {
        if (currCap - w < 0) {
            ships++;
            if (ships > days) {
                return false;
            }
            currCap = cap;
        }
        currCap -= w;
    }
    return true;
}
public:
    int shipWithinDays(vector<int>& w, int d) {
        int sum = accumulate(w.begin(), w.end(), 0);

        int l = *max_element(w.begin(), w.end()), r = sum, ans = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (!canShip(w, d, mid)) l = mid + 1;
            else ans = mid, r = mid - 1;
        }

        return ans;
    }
};