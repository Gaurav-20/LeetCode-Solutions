class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        // lis >= 3
        vector<int> dp = { nums[0] };
        for (int i = 1; i < n; i++) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            } else {
                int it = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[it] = nums[i];
            }
        }
        return dp.size() >= 3;
    }
};