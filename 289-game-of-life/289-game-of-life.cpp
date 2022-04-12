class Solution {
public:
    int dirX[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    int dirY[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                count = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + dirX[k];
                    int ny = j + dirY[k];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] & 1) {
                        count++;
                    }
                }
                if (!board[i][j]) {
                    if (count == 3) {
                        board[i][j] = 2;
                    }
                } else if (count < 2 || count > 3) {
                    board[i][j] = 3;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1 || board[i][j] == 2) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};