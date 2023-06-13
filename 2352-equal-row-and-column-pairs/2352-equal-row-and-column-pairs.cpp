class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, vector<int>> row, col;
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                v.push_back(grid[i][j]);
            }
            row[v].push_back(i);
        }
        for (int j = 0; j < n; j++) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                v.push_back(grid[i][j]);
            }
            col[v].push_back(j);
        }
        int res = 0;
        for (auto it: col) {
            res += it.second.size() * row[it.first].size();
        }
        return res;
    }
};