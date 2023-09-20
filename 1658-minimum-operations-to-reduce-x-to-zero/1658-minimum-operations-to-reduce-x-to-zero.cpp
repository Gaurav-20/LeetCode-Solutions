class Solution {
public:
    int maximalSubarraySizeWithSumValue(vector<int>& nums, long long K) {
        int i = 0, j = 0, sum = 0;
        int maxLen = INT_MIN;
        while (j < nums.size()) {
            sum += nums[j];
            if (sum == K) {
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else if (sum < K) {
                j++;
            } else if (sum > K) {
                while (sum > K) {
                    sum -= nums[i];
                    i++;
                }
                if (sum == K) {
                    maxLen = max(maxLen, j - i + 1);
                }
                j++;
            }
        }
        return maxLen;
    }
    
    int minOperations(vector<int>& nums, int x) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long value = sum - x;
        if (value < 0) {
            return -1;
        }
        if (value == 0) {
            return nums.size();
        }
        int maxSubarrayLen = maximalSubarraySizeWithSumValue(nums, value);
        return (maxSubarrayLen == INT_MIN) ? -1: nums.size() - maxSubarrayLen;
    }
};