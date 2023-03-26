class Graph {
    int V;
    list<int> *adj;
    void fillOrder(int v, bool visited[], stack<int> &Stack);
    void DFSUtil(int v, bool visited[], int &count);
    bool isCyclicUtil(int v, bool visited[], bool *rs);

public:
    Graph(int V);
    void addEdge(int v, int w);
    int getSCCMaxSize();
    Graph getTranspose();
    bool isCyclic();
};
 
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}


void Graph::DFSUtil(int v, bool visited[], int &count) {
    visited[v] = true;
    count++;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited, count);
        }
    }
}
 
Graph Graph::getTranspose() {
    Graph g(V);
    for (int v = 0; v < V; v++) {
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
 
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack)) {
                return true;
            } else if (recStack[*i]) {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}
 
void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            fillOrder(*i, visited, Stack);
        }
    }
    Stack.push(v);
}

bool Graph::isCyclic() {
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
    
    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicUtil(i, visited, recStack)) {
            return true;
        }
    }
    return false;
}

int Graph::getSCCMaxSize() {
    stack<int> Stack;
    int res = -1;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            fillOrder(i, visited, Stack);
        }
    }
    
    Graph gr = getTranspose();

    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();
        if (!visited[v]) {
            int count = 0;
            gr.DFSUtil(v, visited, count);
            res = max(res, count);
        }
    }
    return res;
}

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        Graph graph(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                graph.addEdge(i, edges[i]);
            }
        }
        if (!graph.isCyclic()) {
            return -1;
        }
        return graph.getSCCMaxSize();
    }
};