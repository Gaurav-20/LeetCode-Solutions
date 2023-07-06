class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0;
        int res = INT_MAX;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum >= target) {
                sum -= nums[i];
                res = min(j - i + 1, res);
                i++;
            }
            j++;
        }
        if (res == INT_MAX) {
            return 0;
        }
        return res;
    }
};