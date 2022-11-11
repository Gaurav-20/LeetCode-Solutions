class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = size(nums);
        if (len == 0) {
            return 0;
        }
        int slow = 0;
        for (int fast = 1; fast < len; fast++) {
            if (nums[slow] != nums[fast]) {
                slow += 1;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};