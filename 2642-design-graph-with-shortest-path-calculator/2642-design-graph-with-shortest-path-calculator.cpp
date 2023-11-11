typedef pair<long long, int> pii;

class Graph {
public:
    int numNodes;
    vector<vector<pii>> graph;
    
    Graph(int n, vector<vector<int>>& edges) {
        this->numNodes = n;
        graph.resize(n);
        for (vector<int>& edge: edges) {
            addEdge(edge);
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({ edge[1], edge[2] });
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<long long> dist(numNodes, LLONG_MAX);
        pq.push({ 0LL, node1 });
        dist[node1] = 0;
        while (!pq.empty()) {
            long long weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (pii& neigh: graph[node]) {
                if (dist[neigh.first] > dist[node] + neigh.second) {
                    dist[neigh.first] = dist[node] + neigh.second;
                    pq.push({ weight + neigh.second, neigh.first });
                }
            }
        }
        return (dist[node2] == LLONG_MAX) ? -1: dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */