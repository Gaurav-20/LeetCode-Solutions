class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        prefixSum[0] = 1;
        int count = 0, oddCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) {
                oddCount++;
            }
            if (oddCount >= k) {
                count += prefixSum[oddCount - k];
            }
            prefixSum[oddCount] += 1;
        }
        return count;
    }
}