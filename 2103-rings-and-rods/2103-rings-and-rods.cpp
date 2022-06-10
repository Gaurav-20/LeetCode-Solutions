class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, vector<char>> mp;
        for (int i = 0; i < rings.size(); i += 2) {
            char color = rings[i];
            int rod = rings[i + 1] - '0';
            if (mp.find(rod) == mp.end()) {
                mp[rod].push_back(color);
            } else {
                vector<char> temp = mp[rod];
                if (find(temp.begin(), temp.end(), color) == temp.end()) {
                    mp[rod].push_back(color);
                }
            }
        }
        int res = 0;
        for (auto it : mp) {
            res += size(it.second) == 3;
        }
        return res;
    }
};