class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int curr = matrix[mid / m][mid % m];
            if (curr == target) {
                return true;
            } else if (curr < target) {
                l = mid + 1;
            } else { 
                r = mid - 1;
            }
        }
        return false;
    }
};