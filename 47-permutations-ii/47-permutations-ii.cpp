class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int>& nums, int it, int n) {
        if (it >= n) {
            res.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for (int i = it; i < n; i++) {
            if (st.count(nums[i]) == 1) {
                continue;
            }
            st.insert(nums[i]);
            swap(nums[i], nums[it]);
            solve(nums, it + 1, n);
            swap(nums[i], nums[it]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums, 0, nums.size());
        return res;
    }
};