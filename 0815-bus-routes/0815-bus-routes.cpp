class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> mp;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop: routes[i]){
                mp[stop].push_back(i);
            }
        }
        
        queue<pair<int, int>> q;
        q.push({ source, 0 });
        unordered_set<int> s = { source };
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if (p.first == target) {
                return p.second;
            }
            for (int bus: mp[p.first]) {
                for (int stop: routes[bus]) {
                    if (!s.contains(stop)) {
                        q.push({ stop, p.second + 1 });
                        s.insert(stop);
                    }
                }
                routes[bus] = {};
            }
        }
        return -1;
    }
};