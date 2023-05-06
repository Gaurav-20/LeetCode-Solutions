const int MOD = 1e9 + 7;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size(), left = 0, right = n - 1;
        vector<int> pows(n, 1);
        for (int i = 1 ; i < n ; i++) {
            pows[i] = (pows[i - 1] * 2) % MOD;
        }
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                res = (res + pows[right - left]) % MOD;
                left++;
            }
        }
        return res;
    }
};