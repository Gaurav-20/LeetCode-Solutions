class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& n: nums) {
            mp[n]++;
        }
        int res = 0;
        for (auto it: mp) {
            res += it.second * (it.second - 1) / 2;
        }
        return res;
    }
};