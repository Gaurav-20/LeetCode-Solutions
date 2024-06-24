class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length, result = 0, flipState = 0;
        int[] isFlipped = new int[n];

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipState ^= isFlipped[i - k];
            }
            if (nums[i] == flipState) {
                if (i + k > n) {
                    return -1;
                }
                result += 1;
                flipState ^= 1;
                isFlipped[i] = 1;
            }
        }
        return result;
    }
}