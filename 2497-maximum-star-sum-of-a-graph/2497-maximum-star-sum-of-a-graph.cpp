vector<int> values;
bool compare(const int& a, const int& b) {
    return values[a] > values[b];
}

class Solution {
public:
    
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<int> graph[n];
        values = vals;
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int res = *max_element(vals.begin(), vals.end());
        for (int i = 0; i < n; i++) {
            vector<int> adj = graph[i];
            sort(adj.begin(), adj.end(), compare);
            int curr = vals[i];
            int len = min(k, (int) adj.size());
            for (int j = 0; j < len; j++) {
                if (vals[adj[j]] <= 0) {
                    break;
                } else {
                    curr += vals[adj[j]];
                }
            }
            res = max(res, curr);
        }
        return res;
    }
};