class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length;
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            StringBuilder builder = new StringBuilder();
            for (int j = 0; j < n; j++) {
                builder.append(grid[i][j] + "/");
            }
            String str = builder.toString();
            map.put(str, map.getOrDefault(str, 0) + 1);
        }
        int result = 0;
        for (int j = 0; j < n; j++) {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < n; i++) {
                builder.append(grid[i][j] + "/");
            }
            String str = builder.toString();
            result += map.getOrDefault(str, 0);
        }
        return result;
    }
}