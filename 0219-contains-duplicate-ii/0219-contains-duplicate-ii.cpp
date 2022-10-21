class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prevIdx;
        for (int i = 0; i < n; i++) {
            if (prevIdx.find(nums[i]) != prevIdx.end()) {
                if (i - prevIdx[nums[i]] <= k) {
                    return true;
                }
            }
            prevIdx[nums[i]] = i;
        }
        return false;
    }
};