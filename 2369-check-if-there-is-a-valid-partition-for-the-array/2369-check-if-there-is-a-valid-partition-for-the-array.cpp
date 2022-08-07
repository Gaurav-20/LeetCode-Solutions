class Solution {
public:
    int n;
    
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= n) {
            return 1;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        if (i + 1 < n && nums[i] == nums[i + 1]) {
            if (solve(nums, i + 2, dp)) {
                return 1;
            }
            if (i + 2 < n && nums[i] == nums[i + 2]) {
                if (solve(nums, i + 3, dp)) {
                    return 1;
                }
            }
        }
        if (i + 2 < n && nums[i] == nums[i + 1] - 1 && nums[i] == nums[i + 2] - 2) {
            if (solve(nums, i + 3, dp)) {
                return 1;
            }
        }
        return dp[i] = 0;
    }
    
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, 0, dp);
    }
};