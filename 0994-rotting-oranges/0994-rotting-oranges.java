class Solution {
    public int m;
    public int n;
    
    public int orangesRotting(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        List<List<Integer>> cache = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    list.add(Integer.MIN_VALUE); // This will never rot
                } else if (grid[i][j] == 1) {
                    list.add(Integer.MAX_VALUE); // This will rot, at some time, we will find out
                } else {
                    list.add(0); // This has been already rotten
                }
            }
            cache.add(list);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (cache.get(i).get(j) == 0) {
                    spreadRottenState(cache, i, j, 0);
                }
            }
        }
        
        int result = Integer.MIN_VALUE;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = Math.max(result, cache.get(i).get(j));
            }
        }
        if (result == Integer.MIN_VALUE) {
            result = 0;
        }
        if (result == Integer.MAX_VALUE) {
            result = -1;
        }
        return result;
    }
    
    public void spreadRottenState(List<List<Integer>> cache, int x, int y, int time) {
        if (x < 0 || y < 0 || x >= m || y >= n || cache.get(x).get(y) < time) {
            return;
        }
        cache.get(x).set(y, Math.min(cache.get(x).get(y), time));
        spreadRottenState(cache, x - 1, y, time + 1);
        spreadRottenState(cache, x, y - 1, time + 1);
        spreadRottenState(cache, x + 1, y, time + 1);
        spreadRottenState(cache, x, y + 1, time + 1);
    }
}