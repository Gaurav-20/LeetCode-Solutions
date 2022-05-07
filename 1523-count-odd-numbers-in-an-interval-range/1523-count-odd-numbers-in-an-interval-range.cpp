class Solution {
public:
    int countOdds(int low, int high) {
        int res = 0;
        if (low == high) {
            return low & 1;
        }
        if (low & 1) {
            low++, res++;
        }
        if (high & 1) {
            high--, res++;
        }
        if (low >= high) {
            return res;
        }
        return res + (high - low) / 2;
    }
};