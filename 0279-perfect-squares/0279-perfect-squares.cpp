class Solution {
public:
    int numSquares(int n) {
        vector<int> cache(n + 1, INT_MAX);
        cache[0] = 0;
        cache[1] = 1;
        for (int num = 2; num <= n; num++) {
            for (int i = 1; i * i <= num; i++) {
                cache[num] = min(cache[num], 1 + cache[num - (i * i)]);
            }
        }
        return cache[n];
    }
};