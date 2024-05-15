class Solution {
    public int n;
    public int[] dirs;
    
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        n = grid.size();
        dirs = new int[] { 0, 1, 0, -1, 0 };
        Integer[][] cache = new Integer[n][n];
        Queue<int[]> multiSourceQueue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid.get(i).get(j) == 1) {
                    multiSourceQueue.add(new int[]{ i, j });
                    cache[i][j] = 0;
                } else {
                    cache[i][j] = -1;
                }
            }
        }
        while (!multiSourceQueue.isEmpty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                int[] curr = multiSourceQueue.poll();
                for (int i = 0; i < 4; i++) {
                    int di = curr[0] + dirs[i];
                    int dj = curr[1] + dirs[i + 1];
                    int val = cache[curr[0]][curr[1]];
                    if (di >= 0 && dj >= 0 && di < n && dj < n && cache[di][dj] == -1) {
                        cache[di][dj] = val + 1;
                        multiSourceQueue.add(new int[]{ di, dj });
                    }
                }
            }
        }
        int low = 0, high = 100000, res = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(cache, mid)) {
                low = mid + 1;
                res = mid;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
    
    public boolean possible(Integer[][] cache, int safe) {
        if (cache[0][0] < safe) {
            return false;
        }
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[n][n];
        queue.offer(new int[]{ 0, 0 });
        visited[0][0] = true;
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int x = curr[0], y = curr[1];
            if (x == n - 1 && y == n - 1) {
                return true;
            }
            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k], ny = y + dirs[k + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && cache[nx][ny] >= safe && !visited[nx][ny]) {
                    queue.offer(new int[] { nx, ny });
                    visited[nx][ny] = true;
                }
            }
        }
        return false;
    }
}