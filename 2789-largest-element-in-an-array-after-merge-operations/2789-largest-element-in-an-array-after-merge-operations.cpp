class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> nums2(n);
        for (int i = 0; i < n; i++) {
            nums2[i] = nums[i];
        }
        for (int i = n - 1; i > 0; i--) {
            if (nums2[i - 1] <= nums2[i]) {
                nums2[i - 1] += nums2[i];
            }
        }
        return nums2[0];
    }
};