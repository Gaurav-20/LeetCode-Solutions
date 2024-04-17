class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int result = 0;
        if (nums2.length % 2 == 1) {
            for (int n : nums1) {
                result = result ^ n;
            }
        }
        if (nums1.length % 2 == 1) {
            for (int n : nums2) {
                result = result ^ n;
            }
        }
        return result;
    }
}