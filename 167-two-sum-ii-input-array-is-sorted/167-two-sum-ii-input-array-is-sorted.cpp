class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int curr = nums[low] + nums[high];
            if (curr == target) {
                return {low + 1, high + 1};
            } else if (curr < target) {
                low++;
            } else {
                high--;
            }
        }
        return {-1, -1};
    }
};