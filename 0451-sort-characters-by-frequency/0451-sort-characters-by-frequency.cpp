map<char, int> mp;
map<int, vector<char>> rmp;
class Solution {
public:
    string frequencySort(string s) {
        mp.clear();
        rmp.clear();
        for (char& x : s) {
            mp[x]++;
        }
        for (auto x : mp) {
            rmp[x.second].push_back(x.first);
        }
        string res = "";
        for (auto it = rmp.rbegin(); it != rmp.rend(); it++) {
            for (int i = 0; i < it->second.size(); i++) {
                for (int j = 0; j < it->first; j++) {
                    res += it->second[i];
                }
            }
        }
        return res;
    }
};