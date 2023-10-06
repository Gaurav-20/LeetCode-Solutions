class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        long long res = 1;
        while (n > 3) {
            if (n == 4) {
                res *= 4;
            } else {
                res *= 3;
            }
            n -= 3;
        }
        res *= n;
        return res;
    }
};