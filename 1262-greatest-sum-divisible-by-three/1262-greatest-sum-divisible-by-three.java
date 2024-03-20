class Solution {
    
    public int[][] dp;
    
    public int maxSumDivThree(int[] nums) {
        dp = new int[nums.length][3];
        for (int i = 0; i < nums.length; i++) {
            dp[i] = new int[]{ -1, -1, -1 };
        }
        return solve(nums, 0, 0);
    }
    
    int solve(int[] nums, int i, int sum) {
        if (i == nums.length) {
            return (sum == 0) ? 0 : Integer.MIN_VALUE;
        }
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }
        return dp[i][sum] = Math.max(solve(nums, i + 1, sum), 
                                     nums[i] + solve(nums, i + 1, (sum + nums[i]) % 3));
    }
}