class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<int> curr, vector<vector<int>>& res) {
        if (curr.size() > 1) {
            res.push_back(curr);
        }
        set<int> used;
        for (int i = idx; i < nums.size(); i++) {
            if (used.find(nums[i]) != used.end()) {
                continue;
            }
            if (curr.size() == 0 || curr.back() <= nums[i]) {
                curr.push_back(nums[i]);
                used.insert(nums[i]);
                solve(nums, i + 1, curr, res);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums, 0, curr, res);
        return res;
    }
};