class Solution {
public:
    set<vector<int>> st;
    
    void solve(vector<int>& candidates, vector<int> curr, int i, int n, int target) {
        if (target < 0) {
            return;
        }
        if (i == n) {
            if (target == 0) {
                st.insert(curr);
            }
            return;
        }
        curr.push_back(candidates[i]);
        solve(candidates, curr, i, n, target - candidates[i]);
        solve(candidates, curr, i + 1, n, target - candidates[i]);
        curr.pop_back();
        solve(candidates, curr, i + 1, n, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        st.clear();
        solve(candidates, {}, 0, n, target);
        vector<vector<int>> res;
        for (auto it: st) {
            res.push_back(it);
        }
        return res;
    }
};