class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (vector<int>& row: matrix) {
            reverse(row.begin(), row.end());
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) {
            return true;
        }
        for (int rotateCount = 1; rotateCount <= 3; rotateCount++) {
            rotate(mat);
            if (mat == target) {
                return true;
            }
        }
        return false;
    }
};