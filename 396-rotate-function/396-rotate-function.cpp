class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) {
            return 0;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> F(n);
        for (int i = 0; i < n; i++) {
            F[0] += nums[i] * i;
        }
        for (int i = 1; i < n; i++) {
            F[i] = F[i - 1] + sum - (n * nums[n - i]);
        }
        return *max_element(F.begin(), F.end());
    }
};