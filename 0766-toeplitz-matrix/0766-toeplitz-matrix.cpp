class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp.find(i - j) == mp.end()) {
                    mp[i - j] = matrix[i][j];
                } else if (mp[i - j] != matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};