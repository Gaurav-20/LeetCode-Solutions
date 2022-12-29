#define T pair<long long, long long>

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<T, vector<T>, greater<>> pq;
        long long n = tasks.size(), time = 0, i = 0;
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        vector<int> res;
        while (i < n || pq.size() > 0) {
            if (pq.empty()) {
                time = max(time, (long long) tasks[i][0]);
            }
            while (i < n && time >= tasks[i][0]) {
                pq.push({ tasks[i][1], tasks[i][2] });
                i++;
            }
            auto [pro, index] = pq.top();
            pq.pop();
            time += pro;
            res.push_back(index);
        }
        return res;
    }
};