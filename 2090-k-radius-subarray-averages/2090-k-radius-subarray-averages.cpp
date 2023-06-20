class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) {
            return nums;
        }
        int n = nums.size();
        vector<int> avgs(n, -1);
        if (2 * k >= n) {
            return avgs;
        }
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        int windowSize = 2 * k + 1;
        for (int i = 0; i < n; i++) {
            if (i - k < 0 || i + k >= n) {
                continue;
            } else {
                avgs[i] = (prefixSum[i + k] - prefixSum[i - k] + nums[i - k]) / windowSize;
            }
        }
        return avgs;
    }
};