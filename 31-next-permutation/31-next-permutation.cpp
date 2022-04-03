class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind1 = -1, len = size(nums);
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind1 = i;
                break;
            }
        }
        if (ind1 == -1) {
            reverse(begin(nums), end(nums));
            return;
        }
        for (int i = len - 1; i > ind1; i--) {
            if (nums[i] > nums[ind1]) {
                swap(nums[i], nums[ind1]);
                reverse(nums.begin() + ind1 + 1, nums.end()); 
                break;
            }
        }
    }
};