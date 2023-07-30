class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> distinct;
        for (int i = 0; i < n; i++) {
            distinct.insert(nums[i]);
        }
        int distinctCount = distinct.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            distinct.clear();
            for (int j = i; j < n; j++) {
                distinct.insert(nums[j]);
                if (distinct.size() == distinctCount) {
                    result++;
                }
            }
        }
        return result;
    }
};