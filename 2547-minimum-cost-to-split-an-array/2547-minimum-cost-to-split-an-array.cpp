class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0LL);
        for (int i = 1; i <= n; i++) {
            dp[i] = LLONG_MAX;
        }
        for (int i = 0; i < n; i++) {
            map<int, int> freq, ones;
            long long res = 0;
            for (int j = i; j < n; j++) {
                int ct = ++freq[nums[j]];
                if (ct == 2) {
                    res += 2;
                } else if (ct > 2) {
                    res++;
                }
                dp[j + 1] = min(dp[j + 1], dp[i] + res + k);
            }
        }
        return dp[n];
    }
};