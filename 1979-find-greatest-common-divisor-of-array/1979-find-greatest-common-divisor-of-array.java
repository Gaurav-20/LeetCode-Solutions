class Solution {
    public int findGCD(int[] nums) {
        int maxElement = 0, minElement = 1001;
        for (int i = 0; i < nums.length; i++) {
            minElement = Math.min(minElement, nums[i]);
            maxElement = Math.max(maxElement, nums[i]);
        }
        return gcd(minElement, maxElement);
    }
    
    public int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}