class Solution {
    
    public static int[] result;
    static {
        result = new int[46];
        result[0] = 1;
        result[1] = 1;
        for (int i = 2; i <= 45; i++) {
            result[i] = result[i - 1] + result[i - 2];
        }
    }
    
    public int climbStairs(int n) {
        return result[n];
    }
}