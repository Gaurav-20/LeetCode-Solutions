const int MOD = 1e9 + 7;

class Solution {
public:
    int numTilings(int n) {
        unsigned int n0 = 1, n1 = 1,n2 = 2, n3;
        if (n < 2) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        for (int i = 3; i <= n; i++) {
            n3 = ((2 * n2) + n0) % MOD;
            n0 = n1;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
};