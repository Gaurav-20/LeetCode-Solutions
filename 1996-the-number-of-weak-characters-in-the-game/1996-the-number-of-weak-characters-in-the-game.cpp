class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int maxDefense[100002] = {}, res = 0;
        for (auto &p : properties) {
            maxDefense[p[0]] = max(maxDefense[p[0]], p[1]);
        }
        for (int i = 100000; i > 0; i--) {
            maxDefense[i - 1] = max(maxDefense[i - 1], maxDefense[i]);
        }
        for (auto &p : properties) {
            res += maxDefense[p[0] + 1] > p[1];
        }
        return res;
    }
};