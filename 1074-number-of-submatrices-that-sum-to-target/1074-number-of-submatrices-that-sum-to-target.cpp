class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        if (rows < 1) {
            return 0;
        }
        for (int row = 0; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }
        int count = 0, sum = 0;
        unordered_map<int, int> mp; // counter
        for (int colstart = 0; colstart < cols ;colstart++) {
            for (int col = colstart; col < cols; col++) {
                mp.clear();
                mp[0] = 1;
                sum = 0;
                for (int row = 0; row < rows; row++) {
                    sum += matrix[row][col] - (colstart > 0 ? matrix[row][colstart - 1] : 0);
                    count += (mp.find(sum- target) != mp.end() ? mp[sum - target] : 0);
                    mp[sum]++;
                }
            }
        }
        return count;
    }
};