class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int start = -1, end = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != copy[i]) {
                if (start == -1) {
                    start = i;
                }
                end = i;
            }
        }
        if (start == -1) {
            return 0;
        }
        return end - start + 1;
    }
};