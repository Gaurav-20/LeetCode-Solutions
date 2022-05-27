int dp[1000001] = { -1 };

class Solution {
public:
    int numberOfSteps(int num) {
        if (dp[0] == -1) {
            dp[0] = 0;
            dp[1] = 1;
            for (int i = 2; i <= 1000000; i++) {
                if (i & 1) {
                    dp[i] = dp[i - 1] + 1;
                } else {
                    dp[i] = dp[i / 2] + 1;
                }
            }
        }
        return dp[num];
    }
};