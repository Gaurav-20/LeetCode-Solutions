class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int lastTrue = len - 1; // The nearest position from i where the value is true
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] >= lastTrue - i) {
                lastTrue = i;
            }
        }
            
        return lastTrue == 0;
    }
};