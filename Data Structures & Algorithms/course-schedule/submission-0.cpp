class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < numCourses; i++) {
            graph[i] = {};
        }

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

    bool dfs(int idx, vector<int>& vis, unordered_map<int, vector<int>>& graph) {
        if (vis[idx] == 1) {
            return false;
        }

        if(graph[idx].empty()) {
            return true;
        }

        vis[idx] = 1;
        for(auto& x : graph[idx]) {
            if(!dfs(x, vis, graph)) {
                return false;
            }
        }

        vis[idx] = 0;
        graph[idx].clear();
        return true;
    }
};
