class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for (auto it : arr) {
            mp[it]++;
        }
        vector<int> res;
        int i = 1;
        for (auto& it : mp) {
            it.second = i;
            i++;
        }
        for (auto it : arr) {
            res.push_back(mp[it]);
        }
        return res;
    }
};