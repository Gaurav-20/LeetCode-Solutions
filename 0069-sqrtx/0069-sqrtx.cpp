class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        long long low = 1, high = x;
        while (high - low > 1) {
            long long mid = low + (high - low) / 2;
            long long midSqr = mid * mid;
            if (midSqr > x) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return low;
    }
};