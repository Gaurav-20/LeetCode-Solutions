int pos, currI, currJ;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> shifted(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos = ((i * m) + j + k) % (m * n);
                currI = (pos / m);
                currJ = (pos % m);
                shifted[currI][currJ] = grid[i][j];
            }
        }
        return shifted;
    }
};