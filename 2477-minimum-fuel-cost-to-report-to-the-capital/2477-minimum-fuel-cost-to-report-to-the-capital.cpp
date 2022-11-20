#define ll long long
class Solution {
public:
    
    ll solve(vector<vector<int>>& adj, vector<bool>& vis, ll& res, int curr, int& seats) {
        ll people = 0;
        vis[curr] = true;
        for (auto it : adj[curr]) {
            if (!vis[it]) {
                people += solve(adj, vis, res, it, seats);
            }
        }
        people += 1;
        if (curr != 0) {
            res += ((people + seats - 1) / seats);
        }
        return people;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n; i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<bool> vis(n + 1, false);
        ll res = 0;
        solve(adj, vis, res, 0, seats);
        return res;
    }
};