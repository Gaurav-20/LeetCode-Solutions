class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, n = nums.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            if (nums[low] * nums[low] >= nums[high] * nums[high]) {
                res[i] = nums[low] * nums[low];
                low++;
            } else {
                res[i] = nums[high] * nums[high];
                high--;
            }
        }
        return res;
    }
};