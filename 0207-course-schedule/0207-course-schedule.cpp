class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto &v : prerequisites) {
            indegree[v[0]]++;
            graph[v[1]].push_back(v[0]);
        }
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                res.push_back(i);
            }
        }
        for (int i = 0; i < (int) res.size(); i++) {
            int v = res[i];
            for (auto& adj : graph[v]) {
                indegree[adj]--;
                if (indegree[adj] == 0) {
                    res.push_back(adj);
                }
            }
        }
        return res.size() == numCourses;
    }
};