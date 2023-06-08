class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int row = n - 1, col = 0;
        int negatives = 0;
        while (row >= 0) {
            while (col < m && grid[row][col] >= 0) {
                col += 1;
            }
            negatives += m - col;
            row--;
        }
        return negatives;
    }
};