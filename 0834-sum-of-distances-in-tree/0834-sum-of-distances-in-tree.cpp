class Solution {
public:
    int n;
    vector<int> res, count;
    vector<vector<int>> graph;
    
    void dfs(int node, int parent) {
        for (int child : graph[node]) {
       	    if (child != parent) {
   		        dfs(child, node);
   		        count[node] += count[child];
   		        res[node] += res[child] + count[child];
   	        }
        }
    }

    void dfs2(int node, int parent) {
        for (int child : graph[node]) {
   	        if (child != parent) {
   		        res[child] = res[node] - count[child] + n - count[child];
   		        dfs2(child, node);
   	        }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        res = vector<int>(n, 0);
        count = vector<int>(n, 1);
        graph = vector<vector<int>>(n);
        for (vector<int> e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return res;
    }
};