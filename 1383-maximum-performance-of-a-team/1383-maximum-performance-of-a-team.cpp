class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        vector<vector<int>> worker;
        for (int i = 0; i < n; i++) {
            worker.push_back({ speed[i], efficiency[i] });
        }
        sort(worker.begin(), worker.end(), comp);
        long long res = 0, total = 0;
        long minE;
        for (int i = 0; i < k; i++) {
            total += worker[i][0];
            minE = worker[i][1];
            res = max(res, total * minE);
            heap.push(worker[i][0]);
        }
        for (int i = k; i < n; i++) {
            if (worker[i][0] > heap.top()) {
                total += (-heap.top() + worker[i][0]);
                minE = worker[i][1];
                res = max(res, total * minE);
                heap.pop();
                heap.push(worker[i][0]);
            }
        }
        return (int)(res % 1000000007);
    }
};