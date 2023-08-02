class Solution {
public:
    void permuteUtil(vector<int> nums, int l, int r, vector<vector<int>> &res) {
        if (l == r) {
            res.push_back(nums);
            return;
        }
        for (int i = l; i <=r; i++) {
            swap(nums[l], nums[i]);
            permuteUtil(nums, l + 1, r, res);
            swap(nums[l], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        permuteUtil(nums, 0, n - 1, res);
        return res;
    }
};