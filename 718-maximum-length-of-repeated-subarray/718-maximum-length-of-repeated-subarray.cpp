class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n == 0 || m == 0) {
            return 0;
        }
        vector<int> dp(m + 1, 0);
        int res = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                dp[j] = (nums1[i] == nums2[j]) ? 1 + dp[j + 1] : 0;
                res = max(res, dp[j]);
            }
        }

        return res;
    }
};