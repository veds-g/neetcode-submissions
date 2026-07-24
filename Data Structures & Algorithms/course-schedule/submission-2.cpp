class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> vis;

        unordered_map<int, vector<int>> graph;

        for(auto& x : prerequisites) {
            graph[x[1]].push_back(x[0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if (!dfs(i, vis, graph)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int idx, unordered_set<int>& vis, unordered_map<int, vector<int>>& graph) {
        if (vis.contains(idx)) {
            return false;
        }

        vis.insert(idx);
        for(auto& x : graph[idx]) {
            if(!dfs(x, vis, graph)) {
                return false;
            }
        }

        vis.erase(idx);
        return true;
    }
};