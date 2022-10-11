class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        // since dp size can be atmost 3, we can just use 2 vars
        // and instead of lower_bound just use comparison
        int a = INT_MAX, b = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= a) {
                a = nums[i];
            } else if (nums[i] <= b) {
                b = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};