class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        int numOperationsNeeded = 0;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            while (i < n && nums[i] == curr) {
                i++;
            }
            if (i < n) {
                numOperationsNeeded += i;
                i--;
            }
        }
        return numOperationsNeeded;
    }
};