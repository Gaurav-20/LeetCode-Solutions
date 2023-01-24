class Solution {
public:
    void getCoordinates(int n, int pos, int& row, int& col) {
        row = n - 1 - (pos - 1) / n;
        col = (pos - 1) % n;
        if ((n % 2 == 1 && row % 2 == 1) || (n % 2 == 0 && row % 2 == 0)) {
            col = n - 1 - col;
        }
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q; // { square position, number of moves }
        vector<bool> visited(n * n + 1, false);
        q.push({ 1, 0 });
        visited[1] = true;
        while (!q.empty()) {
            int currPos = q.front().first;
            int moves = q.front().second;
            q.pop();
            if (currPos == n * n) {
                return moves;
            }
            for (int next = currPos + 1; next <= min(n * n, currPos + 6); next++) {
                int row, col;
                getCoordinates(n, next, row, col);
                int newPos = (board[row][col] == -1) ? next : board[row][col];
                if (!visited[newPos]) {
                    q.push({ newPos, moves + 1 });
                    visited[newPos] = true;
                }
            }
        }
        return -1;
    }
};