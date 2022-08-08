#define ll long long
#define pll pair<ll, ll>
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for (auto road : roads) {
            int src = road[0], dest = road[1], weight = road[2];
            graph[src].push_back({ dest, weight });
            graph[dest].push_back({ src, weight });
        }
        // minheap used but we can use maxheap too with negative weights insertion
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        vector<ll> dist(n, LLONG_MAX);
        vector<ll> dp(n, 0);
        dp[0] = 1;
        dist[0] = 0;
        pq.push({ 0, 0 });
        while (!pq.empty()) {
            ll node = pq.top().second;
            ll nodeWt = pq.top().first;
            pq.pop();
            
            if (dist[node] < nodeWt) {
                continue;
            }
            for (auto key : graph[node]) {
                ll child = key.first;
                ll wt = key.second;
                if (nodeWt + wt == dist[child]) {
                    dp[child] = (dp[child] + dp[node]) % MOD;
                }
                if (nodeWt + wt < dist[child]) {
                    dp[child] = dp[node] % MOD;
                    dist[child] = nodeWt + wt;
                    pq.push({ dist[child], child });
                }
            }
        }
        return dp[n - 1];
    }
};