class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> winner;
        map<int, int> loser;
        for (vector<int>& match : matches) {
            winner[match[0]]++;
            loser[match[1]]++;
        }
        vector<vector<int>> res(2);
        for (auto it : winner) {
            if (loser[it.first] == 0) {
                res[0].push_back(it.first);
            }
        }
        for (auto it : loser) {
            if (it.second == 1) {
                res[1].push_back(it.first);
            }
        }
        return res;
    }
};