class Solution {
    public int n;
    public int[][] arr;
    public int[] dp;
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        n = startTime.length;
        arr = new int[n][3];
        for (int i = 0; i < n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }
        dp = new int[n];
        Arrays.fill(dp, -1);
        Arrays.sort(arr, (a, b) -> {
            return a[0] - b[0];
        });
        return solve(0);
    }
    
    public int solve(int i) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int id = lowerBound(arr[i][1]);
        return dp[i] = Math.max(
            arr[i][2] + solve(id), // take
            solve(i + 1) // not take
        );
    }
    
    public int lowerBound(int temp) {
        int low = 0, high = n - 1, res = 0;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (arr[mid][0] >= temp) {
                high = mid - 1;
                res = mid;
            } else {
                low = mid + 1;
                res = mid + 1;
            }
        }
        return res;
    }
}