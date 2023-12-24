class Solution {
    public int[] numberGame(int[] nums) {
        Arrays.sort(nums);
        int alice = 0, bob = 1, n = nums.length;
        int[] result = new int[n];
        for (int i = 0; i < n; i += 2) {
            result[bob] = nums[i];
            result[alice] = nums[i + 1];
            bob += 2;
            alice += 2;
        }
        return result;
    }
}