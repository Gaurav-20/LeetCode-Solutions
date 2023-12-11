class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int curr = 0, prev = 0, prevToPrev = 0;
        for (int i = 2; i <= n; i++) {
            curr = Math.min(cost[i - 1] + prev, cost[i - 2] + prevToPrev);
            prevToPrev = prev;
            prev = curr;
        }
        return curr;
    }
}