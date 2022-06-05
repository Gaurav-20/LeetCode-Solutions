class Solution {
public:
    int findFirstPosition(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (high + low) / 2;
            if (nums[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (nums[low] != target) {
            return -1;
        }
        return low;
    }
    
    int findLastPosition(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (high + low) / 2 + 1;
            if (nums[mid] <= target) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        if (nums[high] != target) {
            return -1;
        }
        return high;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = { -1, -1 };
        if (nums.size() == 0) {
            return res;
        }
        res[0] = findFirstPosition(nums, target);
        res[1] = findLastPosition(nums, target);
        return res;
    }
};