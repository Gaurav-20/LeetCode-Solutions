class Solution {
public:
    int signum(int n) {
        return (n > 0) ? 1 : ((n < 0) ? -1 : 0);
    }
    
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return true;
        }
        int expectedSignOfDiff = signum(nums[1] - nums[0]);
        for (int i = 2; i < n; i++) {
            int currSignOfDiff = signum(nums[i] - nums[i - 1]);
            if (expectedSignOfDiff == 0) {
                expectedSignOfDiff = currSignOfDiff;
            }
            if (currSignOfDiff == 0 || currSignOfDiff == expectedSignOfDiff) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};