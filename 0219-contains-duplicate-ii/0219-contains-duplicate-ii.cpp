class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto it : mp) {
            vector<int> v = it.second;
            for (int i = 1; i < v.size(); i++) {
                if (v[i] - v[i - 1] <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};