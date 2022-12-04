class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long left = 0LL, right = accumulate(nums.begin(), nums.end(), 0LL), n = nums.size();
        long long minAvg = LLONG_MAX, res = -1;
        for (long long i = 0; i < n; i++) {
            left += nums[i];
            right -= nums[i];
            long long rAvg = n - i - 1 == 0 ? 0 : right / (n - i - 1); 
            long long avg = abs(left / (i + 1) - rAvg);
            if (avg < minAvg) {
                minAvg = avg;
                res = i;
            }
        }
        return res;
    }
};