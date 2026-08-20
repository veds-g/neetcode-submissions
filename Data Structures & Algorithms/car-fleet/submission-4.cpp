class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        int n = p.size();
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {p[i], s[i]};
        }
        sort(cars.rbegin(), cars.rend());

        vector<double> stk;
        for (auto& car : cars) {
            double time = (double)(target - car.first) / car.second;
            stk.push_back(time);

            if (stk.size() >= 2 and time <= stk[stk.size() - 2]) {
                stk.pop_back();
            }
        }
        return stk.size();
    }
};
