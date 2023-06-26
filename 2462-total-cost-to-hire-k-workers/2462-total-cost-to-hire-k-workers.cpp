const int LEFT = 1;
const int RIGHT = 2;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        unordered_map<int, int> taken;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long res = 0;
        int low = 0;
        while (low < candidates) {
            pq.push(costs[low]);
            taken[low] = LEFT;
            mp[costs[low]].push(low);
            low++;
        }
        int ct = 0, high = n - 1;
        while (low < high && ct < candidates) {
            pq.push(costs[high]);
            taken[high] = RIGHT;
            mp[costs[high]].push(high);
            high--;
            ct++;
        }
        for (int i = 0; i < k; i++) {
            int curr = pq.top();
            pq.pop();
            int tbd = mp[curr].top();
            res += (long long) costs[tbd];
            mp[curr].pop();
            if (taken[tbd] == LEFT) {
                if (low <= high) {
                    pq.push(costs[low]);
                    taken[low] = LEFT;
                    mp[costs[low]].push(low);
                    low++;
                }
            } else {
                if (low <= high) {
                    pq.push(costs[high]);
                    taken[high] = RIGHT;
                    mp[costs[high]].push(high);
                    high--;
                }
            }
        }
        return res;
    }
};