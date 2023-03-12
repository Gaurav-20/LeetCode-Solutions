class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        vector<long long> pref(n);
        for (int i = 0; i < n; i++) {
            pref[i] = nums[i];
        }
        for (int i = 1; i < n; i++) {
            pref[i] += pref[i - 1];
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += pref[i] > 0;
        }
        return res;
    }
};