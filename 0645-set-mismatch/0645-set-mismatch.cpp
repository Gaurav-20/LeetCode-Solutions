class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[(nums[i] - 1) % n] += n;
        }
        vector<int> res(2);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 2 * n) {
                res[0] = i + 1;
            }
            if (nums[i] <= n) {
                res[1] = i + 1;
            }
        }
        return res;
    }
};