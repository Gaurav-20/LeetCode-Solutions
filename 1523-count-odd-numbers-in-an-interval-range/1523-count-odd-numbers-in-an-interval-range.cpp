class Solution {
public:
    int countOdds(int low, int high) {
        int res = (high - low) >> 1;
        if ((low & 1) || (high & 1)) {
            res++;
        }
        return res;
    }
};