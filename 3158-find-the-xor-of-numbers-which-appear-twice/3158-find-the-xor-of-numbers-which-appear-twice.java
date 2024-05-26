class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        int[] freq = new int[51];
        for (int num : nums) {
            freq[num] += 1;
        }
        int result = 0;
        for (int i = 0; i < 51; i++) {
            if (freq[i] == 2) {
                result ^= i;
            }
        }
        return result;
    }
}