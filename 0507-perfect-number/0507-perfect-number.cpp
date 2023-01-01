class Solution {
public:
    int sumOfDivisorsExcludingNum(int n) {
        int res = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                if (i * i != n) {
                    res += n / i;
                }   
                res += i;
            }
        }
        return res;
    }
    
    bool checkPerfectNumber(int num) {
        return num > 1 && num == sumOfDivisorsExcludingNum(num);
    }
};