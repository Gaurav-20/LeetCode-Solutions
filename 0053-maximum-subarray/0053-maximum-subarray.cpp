class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxTillNow = 0, globalMax = nums[0], n = nums.size();
        for (int i = 0; i < n; i++) {
            maxTillNow += nums[i];
            globalMax = max(globalMax, maxTillNow);
            if (maxTillNow < 0) {
                maxTillNow = 0;
            }
        }
        return globalMax;
    }
};