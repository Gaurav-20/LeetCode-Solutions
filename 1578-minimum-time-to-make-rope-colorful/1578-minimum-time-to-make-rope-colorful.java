class Solution {
    public int minCost(String colors, int[] neededTime) {
        int n = colors.length(), result = 0;
        for (int i = 0; i < n; i++) {
            char curr = colors.charAt(i);
            int maxVal = Integer.MIN_VALUE;
            int sum = 0;
            while (i < n && colors.charAt(i) == curr) {
                sum += neededTime[i];
                maxVal = Math.max(maxVal, neededTime[i]);
                i++;
            }
            result += sum - maxVal; // exclude the largest cost
            if (i < n) {
                i--;
            }
        }
        return result;
    }
}