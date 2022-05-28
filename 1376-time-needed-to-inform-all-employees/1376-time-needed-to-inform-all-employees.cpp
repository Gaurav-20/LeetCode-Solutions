class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> children;
        for (int i = 0; i < n; i++) {
            children[manager[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({ headID, 0 });
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [head, timeTaken] = q.front();
                q.pop();
                int duration = informTime[head] + timeTaken;
                res = max(res, duration);
                for (auto it : children[head]) {
                    q.push({ it, duration });
                }
            }
        }
        return res;
    }
};