class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        int n = nums.length;
        int start = 0;
        long result = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                long len = i - start;
                result += (len * (len + 1)) / 2;
                start = i;
            }
        }
        long len = n - start;
        result += (len * (len + 1)) / 2;
        return result;
    }
}