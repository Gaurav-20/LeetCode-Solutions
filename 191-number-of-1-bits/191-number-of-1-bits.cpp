class Solution {
public:
    int hammingWeight(uint32_t n) {
        int numSetBits = 0;
        while (n) {
            n = n & (n - 1);
            numSetBits++;
        }
        return numSetBits;
    }
};