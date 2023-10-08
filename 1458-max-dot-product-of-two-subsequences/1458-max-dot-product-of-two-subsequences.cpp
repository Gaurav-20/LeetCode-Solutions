class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int firstMax = *max_element(nums1.begin(), nums1.end());
        int firstMin = *min_element(nums1.begin(), nums1.end());
        int secondMax = *max_element(nums2.begin(), nums2.end());
        int secondMin = *min_element(nums2.begin(), nums2.end());
        // Check special cases where all elements are negative
        if ((firstMax < 0 && secondMin > 0) || (firstMin > 0 && secondMax < 0)) {
            return max(firstMax * secondMin, firstMin * secondMax);
        }
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int currentDotProduct = nums1[i] * nums2[j] + dp[i + 1][j + 1];
                dp[i][j] = max({ currentDotProduct, dp[i + 1][j], dp[i][j + 1] });
            }
        }
        return dp[0][0];
    }
};