class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<char, int> keyBit;
        int bitStart = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (islower(grid[i][j])) {
                    keyBit[grid[i][j]] = bitStart++;
                }
            }
        }

        int formEnd = (1 << bitStart) - 1;
        int formSize = (1 << bitStart);

        vector<vector<vector<bool>>> memo(m, vector<vector<bool>>(n, vector<bool>(formSize, false)));

        vector<int> start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    start = { i, j, 0 }; // 0 denoting no key state
                }
            }
        }

        queue<vector<int>> q;
        q.push(start);
        int res = 0; // Step counter

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int row = q.front()[0];
                int col = q.front()[1];
                int form = q.front()[2];
                q.pop();

                // Check if out of bounds
                if (row < 0 || row >= m || col < 0 || col >= n) {
                    continue;
                }

                // Check if position is blocked
                if (grid[row][col] == '#') {
                    continue;
                }

                // Check if the key is required but not collected
                if (isupper(grid[row][col])) {
                    if ((form & (1 << keyBit[tolower(grid[row][col])])) == 0) {
                        continue;
                    }
                }

                // If the position contains a key, collect it
                if (islower(grid[row][col])) {
                    form = form | (1 << keyBit[grid[row][col]]);
                }

                // If all keys are collected, return the step count
                if (form == formEnd) {
                    return res;
                }

                // If the position and form combination has been visited, continue to the next iteration
                if (memo[row][col][form]) {
                    continue;
                }
                memo[row][col][form] = true;

                // Add adjacent positions to the queue
                q.push({ row + 1, col, form });
                q.push({ row - 1, col, form });
                q.push({ row, col + 1, form });
                q.push({ row, col - 1, form });
            }
            res++; // Increment step count
        }
        return -1;
    }
};