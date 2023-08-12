class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> numUniquePaths(m, vector<int>(n, 0));
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (obstacleGrid[row][col] == 0) {
                    if (row == 0 && col == 0) {
                        numUniquePaths[row][col] = 1;
                    } else if (col == 0) {
                        numUniquePaths[row][col] = numUniquePaths[row - 1][col];
                    } else if (row == 0) {
                        numUniquePaths[row][col] = numUniquePaths[row][col - 1];
                    } else {
                        numUniquePaths[row][col] = numUniquePaths[row - 1][col] + numUniquePaths[row][col - 1];
                    }
                }
            }
        }
        return numUniquePaths[m - 1][n - 1];
    }
};