class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = n; i < 2 * n; i++) {
            nums[i] = (nums[i] * 1024) + nums[i - n];
        }

        int index = 0;
        for(int i = n; i < 2 * n; i++, index += 2) {
            nums[index] = nums[i] % 1024;
            nums[index + 1] = nums[i] / 1024;
        }

        return nums;
    }
};