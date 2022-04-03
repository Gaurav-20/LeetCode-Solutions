class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int moves = 0;
        int tar = target;
        while (startValue != tar) {
            if (tar % 2 == 0 && startValue < tar) {
                tar /= 2;
            } else if (tar > startValue) {
                tar++;
            } else {
                moves += abs(tar - startValue) - 1;
                tar = startValue;
            }
            moves++;
        }
        return moves;
    }
};