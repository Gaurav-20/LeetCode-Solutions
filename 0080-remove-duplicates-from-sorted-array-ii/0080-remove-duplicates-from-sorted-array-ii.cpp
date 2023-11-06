class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0], count = 1, len = nums.size();
        int slow = 1;
        for (int fast = 1; fast < len; fast++) {
            if (nums[fast] == curr) {
                count++;
                if (count <= 2) {
                    nums[slow] = nums[fast];
                    slow++;
                }
            } else {
                curr = nums[fast];
                count = 1;
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};