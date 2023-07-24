class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long absN = abs((long) n);
        while (absN > 0) {
            if (absN & 1)
                res *= x;
            absN >>= 1;
            x *= x;
        }
        return n < 0 ?  1.0 / res : res;
    }
};