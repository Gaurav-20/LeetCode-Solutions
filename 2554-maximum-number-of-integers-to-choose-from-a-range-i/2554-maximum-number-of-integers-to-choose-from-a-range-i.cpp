class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban;
        for (int b : banned) {
            ban.insert(b);
        }
        int res = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            if (ban.find(i) == ban.end()) {
                if (sum + i <= maxSum) {
                    sum += i;
                    res++;
                }
            }
        }
        return res;
    }
};