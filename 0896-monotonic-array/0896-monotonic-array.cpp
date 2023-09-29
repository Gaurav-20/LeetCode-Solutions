class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return true;
        }
        bool increasing = true, decreasing = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                increasing = false;
            }
            if (nums[i] > nums[i - 1]) {
                decreasing = false;
            }
            if (!increasing && !decreasing) {
                return false;
            }
        }
        return true;
    }
};