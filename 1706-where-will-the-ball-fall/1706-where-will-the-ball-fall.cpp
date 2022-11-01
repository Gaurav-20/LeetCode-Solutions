class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int i1 = i, i2;
            for (int j = 0; j < n; j++) {
                i2 = i1 + grid[j][i1];
                if (i2 < 0 || i2 >= m || grid[j][i2] != grid[j][i1]) {
                    i1 = -1;
                    break;
                }
                i1 = i2;
            }
            res[i] = i1;
        }
        return res;
    }
};