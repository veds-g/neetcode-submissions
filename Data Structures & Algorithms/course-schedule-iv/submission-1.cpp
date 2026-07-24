class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, set<int>> adj, pre;
        vector<int> indegree(numCourses, 0);
        
        for(auto& prereq: prerequisites) {
            adj[prereq[0]].insert(prereq[1]);
            indegree[prereq[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front(); q.pop();
            
            for(int nei : adj[node]) {
                pre[nei].insert(node);
                pre[nei].insert(pre[node].begin(), pre[node].end());
                indegree[nei]--;
                if(indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }


        vector<bool> res;
        for(auto& query : queries) {
            res.push_back(pre[query[1]].contains(query[0]));
        }

        return res;
    }
};

