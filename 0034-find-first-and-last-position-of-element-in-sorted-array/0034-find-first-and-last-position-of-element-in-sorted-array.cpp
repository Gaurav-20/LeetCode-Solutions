class Solution {
public:
    int findStartPosition(vector<int>& nums, int n, int target) {
        int low = 0, high = n - 1;
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (nums[low] == target) {
            return low;
        } else if (nums[high] == target) {
            return high;
        } else {
            return -1;
        }
    }
    
    int findEndPosition(vector<int>& nums, int n, int target) {
        int low = 0, high = n - 1;
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        if (nums[high] == target) {
            return high;
        } else if (nums[low] == target) {
            return low;
        } else {
            return -1;
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n <= 0) {
            return { -1, -1 };
        }
        int start = findStartPosition(nums, n, target);
        if (start == -1) {
            return { -1, -1 };
        }
        int end = findEndPosition(nums, n, target);
        return { start, end };
    }
};