class Solution {
public:
    void solve(vector<vector<int>>& res, vector<vector<int>>& adj, vector<int>& store, int i) {
        store.push_back(i);
        if (i == adj.size() - 1) {
            res.push_back(store);
        } else {
            for (auto j : adj[i]) {
                solve(res, adj, store, j);
            }
        }
        store.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> store;
        solve(res, graph, store, 0);
        return res;
    }
};