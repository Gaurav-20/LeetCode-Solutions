int dp[105];

class Solution {
public:
    int solve(vector<int>& nums, int it, int len) {
        if (it >= len) {
            return 0;
        }
        if (dp[it] != -1) {
            return dp[it];
        }
        return dp[it] = max(nums[it] + solve(nums, it + 2, len), solve(nums, it + 1, len));
    }
    
    int rob(vector<int>& nums) {
        int len = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, len);
    }
};