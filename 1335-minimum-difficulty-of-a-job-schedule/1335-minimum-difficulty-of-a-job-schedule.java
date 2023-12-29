class Solution {
    public int len;
    public int[] jobDifficulty;
    public int[][][] cache;
    
    public int minDifficulty(int[] jobDifficulty, int days) {
        this.len = jobDifficulty.length;
        this.jobDifficulty = jobDifficulty;
        if (len < days) {
            return -1;
        }
        int max = Arrays.stream(jobDifficulty).max().getAsInt();
        this.cache = new int[len + 1][days + 1][max + 1];
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= days; j++) {
                Arrays.fill(cache[i][j], -1);
            }
        }
        return solve(0, days, 0);
    }
    
    public int solve(int i, int days, int curMax) {
        if (i == len) {
            if (days == 0) {
                return 0;
            } else {
                return 1000000000;
            }
        }
        if (days == 0) {
            return 1000000000;
        }
        if (cache[i][days][curMax] != -1) {
            return cache[i][days][curMax];
        }
        curMax = Math.max(curMax, jobDifficulty[i]);
        return cache[i][days][curMax] = Math.min(
            solve(i + 1, days, curMax),
            curMax + solve(i + 1, days - 1, 0)
        );
    }
}