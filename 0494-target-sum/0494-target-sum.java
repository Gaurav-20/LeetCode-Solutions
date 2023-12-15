class Solution {
    
    public int n;
    public int target;
    
    public int findTargetSumWays(int[] nums, int target) {
        this.n = nums.length;
        this.target = target;
        return solve(nums, 0, 0);
    }
    
    public int solve(int[] nums, int idx, int sum) {
        if (idx == n) {
            return (sum == target) ? 1 : 0;
        }
        int result = 0;
        result += solve(nums, idx + 1, sum - nums[idx]);
        result += solve(nums, idx + 1, sum + nums[idx]);
        return result;
    }
}