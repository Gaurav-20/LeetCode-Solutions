class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int, int> mp;
        for (int num: nums) {
            mp[num]++;
        }
        vector<int> res;
        for (auto it: mp) {
            if (it.second == 1 && !mp[it.first - 1] && !mp[it.first + 1]) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};