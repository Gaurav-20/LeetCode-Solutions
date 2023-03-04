class Solution {
public:
    long long coloredCells(int n) {
        vector<long long> res(n + 1);
        res[1] = 1LL;
        for (long long i = 2; i <= n; i++) {
            res[i] = res[i - 1] + 4LL * (i - 1);
        }
        return res[n];
    }
};