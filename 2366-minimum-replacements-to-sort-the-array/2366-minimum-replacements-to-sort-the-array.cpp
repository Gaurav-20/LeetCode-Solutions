class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0, n = nums.size();
        if (n <= 1) {
            return 0;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            }
            long long numElements = (nums[i] + nums[i + 1] - 1) / nums[i + 1];
            res += numElements - 1;
            nums[i] = nums[i] / numElements;
        }
        return res;
    }
};