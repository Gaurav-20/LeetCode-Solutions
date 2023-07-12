class Solution {
public:
    unordered_set<int> cycleNodes;
    unordered_set<int> safeNodes;
    
    bool dfs (const vector<vector<int>>& graph, int node, unordered_set<int> visitedNodes) {
	    if (safeNodes.find(node) != safeNodes.end()) {
            return true;
        }
	    if (cycleNodes.find(node) != cycleNodes.end()) {
            return false;
        }
	    if (visitedNodes.find(node) != visitedNodes.end()) {
		    cycleNodes.insert(node);
		    return false;
	    }
	    visitedNodes.insert(node);
	    for (int neigh: graph[node]) {
		    if (!dfs (graph, neigh, visitedNodes)) {
			    cycleNodes.insert(node);
			    return false;
		    }
	    }
	    safeNodes.insert(node);
	    return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
	    unordered_set<int> visitedNodes;
	    for (int i = 0; i < n; i++) {
		    if (dfs(graph, i, visitedNodes)) {
                res.push_back(i);
            }
	    }
	    return res;
    }
};