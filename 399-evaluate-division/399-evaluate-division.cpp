#define PSD pair<string, double>

class Solution {
public:
    unordered_map<string, vector<PSD>> graph;
    
    void addEdge(string src, string dest, double value) {
        graph[src].push_back({ dest, value });
    }
    
    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            addEdge(equations[i][0], equations[i][1], values[i]);
            addEdge(equations[i][1], equations[i][0], 1.0 / values[i]);
        }
    }
    
    double findPath(vector<string>& query) {
        string src = query[0], dest = query[1];
        if (graph.find(src) == graph.end() || graph.find(dest) == graph.end()) {
            return -1.0;
        }
        queue<PSD> q;
        unordered_map<string, bool> visited;
        q.push({ src, 1.0 });
        while (!q.empty()) {
            PSD node = q.front();
            string curr = node.first;
            double currValue = node.second;
            q.pop();
            if (curr == dest) {
                return currValue;
            }
            visited[curr] = true;
            for (PSD neigh : graph[curr]) {
                if (!visited[neigh.first]) {
                    q.push({ neigh.first, currValue * neigh.second });
                }
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        buildGraph(equations, values);
        for (vector<string>& query : queries) {
            res.push_back(findPath(query));
        }
        return res;
    }
};