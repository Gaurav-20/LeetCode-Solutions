class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0, res = 0, n = nums.size();
        long long sum = 0;
        while (right < n) {
            sum += nums[right];
            while ((long long) nums[right] * (right - left + 1) > sum + k) {
                sum -= nums[left];
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};