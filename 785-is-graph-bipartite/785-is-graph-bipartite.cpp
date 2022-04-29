class Solution {
public:
//     bool checkBipartiteDfs(vector<vector<int>>& graph, int node, int parent, vector<int>& color){
//         if (color[node] == -1) {
//             color[node] = 0;
//         }
//         for (auto& it : graph[node]) {
//             if (color[it] == -1) {
//                 color[it] = 1 - color[node];
//                 if (!checkBipartiteDfs(graph, it, node, color))
//                     return false;
//             } else if (color[it] == color[node]) {
//                 return false;
//             }
//         }
//         return true;
//     }
    
//     bool isBipartite(vector<vector<int>>& graph) {
//         DFS code
//         int n = graph.size();
//         vector<int> color(n, -1);
//         for (int i = 0; i < n; i++) {
//             if (!checkBipartiteDfs(graph, i, -1, color)) {
//                 return false;
//             }
//         }
//         return true;
//     }
    
    bool checkBipartiteBfs(vector<vector<int>>& graph, int i, vector<int>& color) {
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto& it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = 1 - color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!checkBipartiteBfs(graph, i, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};