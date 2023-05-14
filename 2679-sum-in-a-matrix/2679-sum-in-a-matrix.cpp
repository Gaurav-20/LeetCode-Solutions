class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (vector<int>& v: nums) {
            sort(v.begin(), v.end(), greater<int>());
        }
        int n = nums.size(), m = nums[0].size();
        int score = 0;
        for (int j = 0; j < m; j++) {
            int curr = 0;
            for (int i = 0; i < n; i++) {
                curr = max(curr, nums[i][j]);
            }
            score += curr;
        }
        return score;
    }
};