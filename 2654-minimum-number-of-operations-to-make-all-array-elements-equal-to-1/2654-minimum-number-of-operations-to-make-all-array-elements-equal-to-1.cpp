class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int oneCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                oneCount++;
            }
        }
        if (oneCount > 0) {
            return n - oneCount;
        }
        int minLength = INT_MAX; // minSubarrayLengthWithGcd1
        for (int i = 0; i < n; i++) {
            int res = nums[i];
            for(int j = i; j < n; j++) {
                res = __gcd(nums[j], res);
                if (res == 1) {
                    minLength = min(minLength, j - i);
                }
            }
        }
        return (minLength == INT_MAX)? -1: n + minLength - 1;
    }
};