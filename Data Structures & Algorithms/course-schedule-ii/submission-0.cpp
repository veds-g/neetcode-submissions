class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans, indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;

        for(auto& x : prerequisites) {
            indegree[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);

            for(int& nextNode : adj[node]) {
                indegree[nextNode]--;

                if (indegree[nextNode] == 0) {
                    q.push(nextNode);
                }
            }
        }

        return ans.size() == numCourses ? ans : vector<int>{};
    }
};
