class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int lastTrueIndex = len - 1;
        for (int i = len - 2; i >= 0; i--) {
            if (lastTrueIndex - i <= nums[i]) {
                lastTrueIndex = i;
            }
        }
        return lastTrueIndex == 0;
    }
};