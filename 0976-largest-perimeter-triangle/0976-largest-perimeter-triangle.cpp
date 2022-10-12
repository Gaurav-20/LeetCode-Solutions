class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] < nums[i - 1] + nums[i - 2]) {
                res = nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return res;
    }
};