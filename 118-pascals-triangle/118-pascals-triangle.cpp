class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for (int i = 0; i < numRows; i++) {
            vector<int> currentRow = { 1 };
            for (int j = 1; j < i; j++) {
                currentRow.push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
            }
            if (i > 0) {
                currentRow.push_back(1);
            }
            pascal.push_back(currentRow);
        }
        return pascal;
    }
};