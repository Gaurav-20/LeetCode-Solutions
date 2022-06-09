class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int start = 0, end = 0, len = nums.size();
        int sum = 0;
        while (end < len) {
            sum += nums[end++];
            while (sum >= target && start <= end) {
                res = min(res, end - start);
                sum -= nums[start++];
            }
            if (start > end) {
                end++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};