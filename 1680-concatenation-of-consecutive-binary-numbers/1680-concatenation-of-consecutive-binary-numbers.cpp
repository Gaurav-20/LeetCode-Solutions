const int MOD = 1000000007;

class Solution {
public:
    int concatenatedBinary(int n) {
        long long sum = 0;
        int len = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                // increment binary length at each power of two
                len++;
            }
            sum = ((sum << len) | i) % MOD;
        }
        return (int) sum;
    }
};