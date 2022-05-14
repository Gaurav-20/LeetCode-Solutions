#define pii pair<int, int>

class Solution {
public:
    vector<vector<pii>> getGraph(vector<vector<int>>& times, int n) {
        vector<vector<pii>> graph(n);
        for (auto& t : times) {
            graph[t[0] - 1].push_back({t[1] - 1, t[2]});
        }
        return graph;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> graph = getGraph(times, n);
        vector<int> distance(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        k--;
        pq.push({0, k});
        distance[k] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for (auto& t : graph[u]) {
                int v = t.first;
                int w = t.second;
                if (distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                    pq.push({distance[v], v});
                }
            }
        }
        int time = 0;
        for (auto d : distance) {
            if (d == INT_MAX) {
                return -1;
            } else {
                time = max(time, d);
            }
        }
        return time;
    }
};