class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        long long res = 0, pre = 0;
        for (int i : nums) {
            pre ^= i;
            res += mp[pre]++;
        }
        return res;
    }
};