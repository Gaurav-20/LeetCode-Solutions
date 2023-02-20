class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        unsigned int low = 0, n = nums.size(), high = nums.size() - 1, mid;
        if (nums[0] >= target) {
            return 0;
        }
        if (nums.back() < target) {
            return n;
        }
        
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target && mid < n - 1 && nums[mid + 1] > target) {
                return mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return mid;
    }
};