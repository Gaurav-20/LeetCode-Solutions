class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalMax = nums[0], localMax = 0;
        for (int& n : nums) {
            localMax += n;
            globalMax = max(globalMax, localMax);
            if (localMax < 0) {
                localMax = 0;
            }
        }
        return globalMax;
    }
};