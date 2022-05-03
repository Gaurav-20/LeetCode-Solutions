class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -1, mini = nums[n - 1], maxi = nums[0];
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[n - 1 - i]);
            if (nums[i] < maxi) {
                end = i;
            }
            if (nums[n - 1 - i] > mini) {
                start = n - 1 - i;
            }
        }
        if (start == -1) {
            return 0;
        }
        return end - start + 1;
    }
};