class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) {
            return false;
        }
        int prevMin = INT_MIN;
        int potentialPeak = len;
        for (int i = len - 1; i >= 0; i--) {
            if (nums[i] < prevMin) {
                return true;
            }
            while (potentialPeak < len && nums[i] > nums[potentialPeak]) {
                prevMin = nums[potentialPeak++];
            }
            potentialPeak--;
            nums[potentialPeak] = nums[i];
        }
        return false;
    }
};