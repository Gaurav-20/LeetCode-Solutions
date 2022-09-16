class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    
    int solve(int i, int k, vector<int> &nums, vector<int> &mults) {
        if (k == m) {
            return 0;
        }
        if (dp[i][k] != INT_MIN) {
            return dp[i][k];
        }
        int x = solve(i + 1, k + 1, nums, mults) + (nums[i] * mults[k]);
        int y = solve(i, k + 1, nums, mults) + (nums[(n - 1) - (k - i)] * mults[k]);
        return dp[i][k] = max(x, y);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mulipliers) {
        n = nums.size(), m = mulipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0, 0, nums, mulipliers);
    }
    
};