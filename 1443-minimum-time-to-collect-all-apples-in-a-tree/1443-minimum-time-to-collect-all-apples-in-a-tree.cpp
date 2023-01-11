class Solution {
public:
    int dfs(vector<vector<int>>& tree, 
            int node, int nodeCost, vector<bool>& visited, vector<bool>& hasApple) {
	    if (visited[node]) {
		    return 0;
	    }
	    visited[node] = true;
        int childrenCost = 0;
        for (auto neigh: tree[node]) {
            childrenCost += dfs(tree, neigh, 2, visited, hasApple);
        }
        if (childrenCost == 0 && !hasApple[node]) {
            return 0;
        }
        return (childrenCost + nodeCost);
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> tree(n);
        for (auto it : edges) {
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n, false);
        return dfs(tree, 0, 0, visited, hasApple);
    }
};