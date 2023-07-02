class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size(), res = 0;
        for (int l = 0; l < n; l++) {
            if (nums[l] % 2 != 0) {
                continue;
            }
            int curr = 0;
            for (int r = l; r < n; r++) {
                if ((nums[r] > threshold) || (r > l && nums[r] % 2 == nums[r - 1] % 2)) {
                    break;
                }
                curr++;
            }
            res = max(res, curr);
        }
        return res;
    }
};