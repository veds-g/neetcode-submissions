class CountSquares {
    unordered_map<long, int> p;
    vector<vector<int>> pts;

    long getKey(int x, int y) {
        return x * 2000 + y;
    }
public:
    CountSquares() {}
    
    void add(vector<int> point) {
        p[getKey(point[0], point[1])]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        int ways = 0;

        int px = point[0], py = point[1];

        for (const auto& pt : pts) {
            int x = pt[0], y = pt[1];
            if (abs(py - y) != abs(px - x) || x == px || y == py) continue;
            ways += p[getKey(x, py)] * p[getKey(px, y)];
        }
        return ways;
    }
};
