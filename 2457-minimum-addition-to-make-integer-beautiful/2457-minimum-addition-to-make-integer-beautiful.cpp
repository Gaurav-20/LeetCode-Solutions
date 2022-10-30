class Solution {
public:
    int digitSum(long long n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        long long res = 0, mul = 1;
        while (digitSum(n) > target) {
            res += mul * ((10 - n % 10) % 10);
            n = (n + (10 - n % 10) % 10) / 10;
            mul *= 10;
        }
        return res;
    }
};