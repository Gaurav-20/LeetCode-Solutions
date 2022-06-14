class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = (n % 2 == 0) ? true : false;
        while (n > 0) {
            if (flag == n % 2) {
                return false;
            }
            flag = !flag;
            n >>= 1;
        }
        return true;
    }
};