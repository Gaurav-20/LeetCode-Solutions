int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {1, -1, 0, 0};

class Solution {
public:
    int m, n;
    
    bool isValid(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited) {
        return (i >= 0 && j >= 0 && i < m && j < n && !visited[i][j]);
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited, string word, int index) {
        visited[x][y] = true;
        if (index == word.size()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dirX[i];
            int ny = y + dirY[i];
            if (isValid(board, nx, ny, visited) && board[nx][ny] == word[index]) {
                if (dfs(board, nx, ny, visited, word, index + 1)) {
                    return true;
                }
            }
        }
        visited[x][y] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == word[0]) {
                    if (dfs(board, i, j, visited, word, 1))
                        return true;
                }
            }
        }
        return false;
    }
};