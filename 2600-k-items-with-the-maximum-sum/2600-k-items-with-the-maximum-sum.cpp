class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int res = 0;
        while (k--) {
            if (numOnes > 0) {
                numOnes--;
                res++;
            } else if (numZeros > 0) {
                numZeros--;
            } else {
                numNegOnes--;
                res--;
            }
        }
        return res;
    }
};