class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num: nums) {
            mp[num]++;
        }
        vector<int> res;
        for (auto it: mp) {
            int ele = it.first;
            int freq = it.second;
            if (freq == 1 && mp.find(ele - 1) == mp.end() && mp.find(ele + 1) == mp.end()) {
                res.push_back(ele);
            }
        }
        return res;
    }
};