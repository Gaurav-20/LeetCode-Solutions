class Solution {
public:
    int minFlips(int a, int b, int c) {
        int numFlips = 0;
        while (a > 0 || b > 0 || c > 0) {
            if (c % 2 == 0) {
                numFlips += (a % 2 == 1);
                numFlips += (b % 2 == 1);
            } else {
                numFlips += (a % 2 == 0) && (b % 2 == 0);
            }
            a /= 2;
            b /= 2;
            c /= 2;
        }
        return numFlips;
    }
};