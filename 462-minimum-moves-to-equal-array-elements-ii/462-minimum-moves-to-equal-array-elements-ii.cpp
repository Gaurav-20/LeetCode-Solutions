class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minMoves = 0, median = nums[nums.size() / 2];
        for (auto it : nums) {
            minMoves += abs(it - median);
        }
        return minMoves;
    }
};