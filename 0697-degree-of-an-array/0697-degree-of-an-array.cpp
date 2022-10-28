class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int res = 0, degree = 0, len = nums.size();
        unordered_map<int, int> first, count;
        for (int i = 0; i < len; i++) {
            if (first.find(nums[i]) == first.end()) {
                first[nums[i]] = i;
            }
            count[nums[i]]++;
            if (count[nums[i]] > degree) {
                degree = count[nums[i]];
                res = i - first[nums[i]] + 1;
            } else if (count[nums[i]] == degree) {
                res = min(res, i - first[nums[i]] + 1);
            }
        }
        return res;
    }
};