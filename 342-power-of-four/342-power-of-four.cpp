class Solution {
public:
    // ffs() function returns the index of first least significant set bit.
    // The indexing starts in ffs() function from 1.
    bool isPowerOfFour(int n) {
        return (n > 0) && (__builtin_popcount(n) == 1) && (ffs(n) % 2 == 1);
    }
};