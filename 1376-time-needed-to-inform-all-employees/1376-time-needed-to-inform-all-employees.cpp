class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if (n == 1) {
            return 0;
        }
        unordered_map<int, vector<int>> children;
        for (int i = 0; i < n; i++) {
            children[manager[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({ headID, 0 }); // node, timeTaken
        int maxTime = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front().first;
                int time = q.front().second;
                q.pop();
                int duration = time + informTime[curr];
                maxTime = max(maxTime, duration);
                for (auto child: children[curr]) {
                    q.push({ child, duration });
                }
            }
        }
        return maxTime;
    }
};