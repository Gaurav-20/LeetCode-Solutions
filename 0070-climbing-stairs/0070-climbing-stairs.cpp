class Solution {
public:
    int ways[46] = { -1 };
    int climbStairs(int n) {
        if (ways[0] == -1) {
            ways[0] = ways[1] = 1;
            for (int i = 2; i <= 45; i++) {
                ways[i] = ways[i - 1] + ways[i - 2];
            }
        }
        return ways[n];
    }
};