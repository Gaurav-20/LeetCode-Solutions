class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            rightSum -= nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};