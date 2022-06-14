class Solution {
public:
    int countBits(int n) {
        int ct = 0;
        while (n > 0) {
            ct++;
            n = n & (n - 1);
        }
        return ct;
    }
    
    int hammingDistance(int x, int y) {
        return countBits(x ^ y);
    }
};