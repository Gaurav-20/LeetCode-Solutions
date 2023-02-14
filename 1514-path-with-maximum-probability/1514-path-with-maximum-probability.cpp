struct Node {
    int node;
    double prob;
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<Node> graph[n];
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            double prob = succProb[i];
            graph[a].push_back({ b, prob });
            graph[b].push_back({ a, prob });
        }
        vector<double> res(n, 0.0); // max prob for each node
        queue<Node> q;
        q.push({ start, 1.0 });
        while (!q.empty()) {
            int parent = q.front().node;
            double prob = q.front().prob;
            q.pop();
            for (auto it : graph[parent]) {
                int child = it.node;
                double nextProb = it.prob;
                if (res[child] >= prob * nextProb) {
                    continue;
                }
                q.push({ child, prob * nextProb });
                res[child] = prob * nextProb;
            }
        }
        return res[end];
    }
};