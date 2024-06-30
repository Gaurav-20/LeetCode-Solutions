class Solution {
    public int maximumLength(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            nums[i] %= 2;
        }
        int seq1 = solve(nums, new int[] { 0, 0 });
        int seq2 = solve(nums, new int[] { 0, 1 });
        int seq3 = solve(nums, new int[] { 1, 0 });
        int seq4 = solve(nums, new int[] { 1, 1 });
        return Math.max(Math.max(seq1, seq2), Math.max(seq3, seq4));
    }
    
    public int solve(int[] nums, int[] seq) {
        int seqIt = 0, result = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == seq[seqIt]) {
                result += 1;
                seqIt = (seqIt + 1) % 2;
            }
        }
        return result;
    }
}