int cache[10001] = { -1 };

class Solution {
public:
    int numSquares(int n) {
        if (cache[0] == -1) {
            cache[0] = 0;
            cache[1] = 1;
            for (int num = 2; num <= 10000; num++) {
                cache[num] = INT_MAX;
                for (int i = 1; i * i <= num; i++) {
                    cache[num] = min(cache[num], 1 + cache[num - (i * i)]);
                }
            }
        }
        return cache[n];
    }
};