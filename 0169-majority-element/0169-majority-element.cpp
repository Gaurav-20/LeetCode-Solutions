class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majorityElement = nums[0];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == majorityElement) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                majorityElement = nums[i];
                count++;
            }
        }
        return majorityElement; // Need not check coz given that it always exists
    }
};