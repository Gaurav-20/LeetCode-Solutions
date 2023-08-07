class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int low = 0, high = rows * cols - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int rowIndex = mid / cols;
            int colIndex = mid % cols;
            if (matrix[rowIndex][colIndex] == target) {
                return true;
            } else if (matrix[rowIndex][colIndex] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};