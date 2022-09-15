class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n & 1) {
            return {};
        }
        unordered_map<int, int> mp;
        for (int c : changed) {
            mp[c]++;
        }
        vector<int> keys;
        for (auto it : mp) {
            keys.push_back(it.first);
        }
        sort(keys.begin(), keys.end());
        vector<int> res;
        for (int x : keys) {
            if (mp[x] > mp[2 * x]) {
                return {};
            }
            for (int i = 0; i < mp[x]; i++, mp[2 * x]--) {
                res.push_back(x);
            }
        }
        return res;
    }
};