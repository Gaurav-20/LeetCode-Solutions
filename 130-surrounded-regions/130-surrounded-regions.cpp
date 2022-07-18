int dir[] = {-1, 0, 1, 0, -1};

class Solution {
public:
    bool visited[200][200];
    int rows, cols;
    void dfs(int row, int col, vector<vector<char>> &board) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] == 'X' || visited[row][col]) {
            return;    
        }
        visited[row][col] = true;
        board[row][col] = '#';
        for (int i = 0; i < 4; i++) {
            dfs(row + dir[i], col + dir[i + 1], board);
        }
    }
    
    void solve(vector<vector<char>> &board) {
        rows = board.size();
        cols = board[0].size();
        memset(visited, false, sizeof(visited));
        
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, board);
            dfs(i, cols - 1, board);
        }

        for (int i = 0; i < cols; i++) {
            dfs(0, i, board);
            dfs(rows - 1, i, board);
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = (board[i][j] == '#') ? 'O': 'X';
            }
        }
    }
};