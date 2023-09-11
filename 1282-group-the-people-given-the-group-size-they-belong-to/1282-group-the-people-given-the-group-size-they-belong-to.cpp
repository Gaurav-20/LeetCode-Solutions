class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < groupSizes.size(); i++) {
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for (auto x: mp) {
            int k = x.first;
            vector<int> f = x.second;
            int c = f.size() / k;
            int l = 0;
            for (int i = 0; i < c; i++) {
                vector<int> ans;
                for (int j = 0; j < k; j++) {
                    ans.push_back(f[l]);
                    l++;
                }
                res.push_back(ans);
            }
        }
        return res;
    }
};