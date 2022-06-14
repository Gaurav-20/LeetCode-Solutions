class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[nums[i] & nums[j]]++;
            }
        }
        for (auto it : mp) {
            for (int i = 0; i < n; i++) {
                if ((nums[i] & it.first) == 0) {
                    res += it.second;
                }
            }
        }
        return res;
    }
};