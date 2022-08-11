class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int nl = nums[left], nr = nums[right], nm = nums[mid];
            if (target == nm) {
                return mid;
            }
            if (nm > nr) {
                if (target < nm && target >= nl) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nm < nl) {
                if (target > nm && target <= nr) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (target < nm) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};