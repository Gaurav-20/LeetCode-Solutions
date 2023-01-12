class Solution {
public:
    
    void solve(vector<vector<int>>& tree, int node, vector<bool>& visited,
        vector<int>& charCount, string& labels, vector<int>& res) {
        
        visited[node] = true;
        int index = labels[node] - 'a';
        int prevCount = charCount[index];
        charCount[index]++;
        for (auto neigh : tree[node]) {
            if (!visited[neigh]) {
                solve(tree, neigh, visited, charCount, labels, res);
            }
        }
        res[node] = charCount[index] - prevCount;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> tree(n);
        for (auto edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n, 0);
        vector<bool> visited(n, false);
        vector<int> charCount(26, 0);
        solve(tree, 0, visited, charCount, labels, res);
        return res;
    }
};