class Solution {
public:
    int n, m;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        m = matrix.size();
        if (m == 0) {
            return res;
        }
        n = matrix[0].size();
        if (n == 0) {
            return res;
        }
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) {
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(matrix, pacific, 0, j);
            dfs(matrix, atlantic, m - 1, j);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back(vector<int>({ i, j }));
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        //up
        if (i - 1 >= 0 && !visited[i - 1][j] && matrix[i - 1][j] >= matrix[i][j]) {
            dfs(matrix, visited, i - 1, j);
        }
        //down
        if (i + 1 < m && !visited[i + 1][j] && matrix[i + 1][j] >= matrix[i][j]) {
            dfs(matrix, visited, i + 1, j);
        }
        //left
        if (j - 1 >= 0 && !visited[i][j - 1] && matrix[i][j - 1] >= matrix[i][j]) {
            dfs(matrix, visited, i, j - 1);
        }
        //right
        if (j + 1 < n && !visited[i][j + 1] && matrix[i][j + 1] >= matrix[i][j]) {
            dfs(matrix, visited, i, j + 1);
        }
    }
};