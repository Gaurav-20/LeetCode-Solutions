class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (vector<int>& g : grid) {
            sort(g.begin(), g.end(), greater<int>());
        }
        int n = grid.size(), m = grid[0].size(), res = 0;
        for (int j = 0; j < m; j++) {
            int mx = -1;
            for (int i = 0; i < n; i++) {
                mx = max(mx, grid[i][j]);
            }
            res += mx;
        }
        return res;
    }
};