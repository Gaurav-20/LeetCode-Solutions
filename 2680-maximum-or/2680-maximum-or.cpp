class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n, 0LL);
        vector<long long> suffix(n, 0LL);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] | nums[i];
        }
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] | nums[i];
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long curr = nums[i] * (1LL << k);
            if (i > 0) {
                curr |= prefix[i - 1];
            }
            if (i < n - 1) {
                curr |= suffix[i + 1];
            }
            res = max(res, curr);
        }
        return res;
    }
};