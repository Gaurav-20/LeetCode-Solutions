class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1, curr = 0;
        while (i < n && j >= 0) {
            curr = matrix[i][j];
            if (curr == target) {
                return true;
            } else if (curr > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};