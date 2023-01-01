class Solution {
public:
    int countDigits(int num) {
        int res = 0, temp = num;
        while (temp > 0) {
            int cur = temp % 10;
            if (num % cur == 0) {
                res++;
            }
            temp /= 10;
        }
        return res;
    }
};