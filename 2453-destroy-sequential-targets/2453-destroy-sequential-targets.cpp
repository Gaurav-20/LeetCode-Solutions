class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int mx = -1;
        for (int i = 0; i < n; i++) {
            int curr = nums[i] % space;
            mp[curr]++;
            mx = max(mx, mp[curr]);
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (mx == mp[nums[i] % space]) {
                res = min(res, nums[i]);
            }
        }
        return res;
    }
};