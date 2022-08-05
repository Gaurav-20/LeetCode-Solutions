unsigned int dp[1001];

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 1; j <= nums.size(); j++) {
                if (i >= nums[j - 1]) {
                    dp[i] += dp[i - nums[j - 1]];
                }
            }
        }
        return (int)dp[target];
    }
};