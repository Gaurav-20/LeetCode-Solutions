class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int> ban;
        for (int b : banned) {
            ban[b] = true;
        }
        int res = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            if (!ban[i]) {
                if (sum + i <= maxSum) {
                    sum += i;
                    res++;
                }
            }
        }
        return res;
    }
};