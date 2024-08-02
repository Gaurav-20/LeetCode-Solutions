class Solution {
    public int minSwaps(int[] nums) {
        int numOnes = 0;
        for (int x: nums) {
            numOnes += x;
        }
        int curr = 0, maxi = 0;
        int n = nums.length;
        for (int i = 0; i < 2 * n; i++) {
            curr += nums[i % n];
            if (i == numOnes - 1) {
                maxi = curr;
            }
            if (i >= numOnes) {
                curr -= nums[(i - numOnes) % n];
                maxi = Math.max(maxi, curr);
            }
        }
        return numOnes - maxi;
    }
}