class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length, moves = 0;
        int dest = n * n;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(1);
        boolean[] visited = new boolean[dest + 1];
        visited[1] = true;
        while (!queue.isEmpty()) {
            int size = queue.size();
            moves += 1;
            while (size-- > 0) {
                int curr = queue.poll();
                for (int dice = 1; dice <= 6; dice++) {
                    int next = Math.min(curr + dice, dest);
                    if (visited[next]) {
                        continue;
                    }
                    visited[next] = true;
                    int row = n - 1 - (next - 1) / n;
                    int col = (next - 1) % n;
                    if ((n % 2) == (row % 2)) {
                        col = n - 1 - col;
                    }
                    if (board[row][col] != -1) {
                        next = board[row][col];
                    }
                    if (next == dest) {
                        return moves;
                    }
                    queue.offer(next);
                }
            }
        }
        return -1;
    }
}