class Solution {
    public int subsetXORSum(int[] nums) {
        int n = nums.length, result = 0;
        for (int i = 0; i < (1 << n); i++) {
            int xor = 0;
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    xor ^= nums[j];
                }
            }
            result += xor;
        }
        return result;
    }
}