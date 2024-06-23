class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length, result = 0;
        boolean flipped = false;
        for (int i = 0; i < n; i++) {
            int curr = flipped ? 1 : 0;
            if (nums[i] == curr) {
                result += 1;
                flipped = !flipped;
            }
        }
        return result;
    }
}