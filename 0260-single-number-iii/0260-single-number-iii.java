class Solution {
    public int[] singleNumber(int[] nums) {
        int xors = Arrays.stream(nums).reduce((a, b) -> a ^ b).getAsInt();
        int lowbit = xors & -xors;
        int[] result = new int[2];
        for (int num : nums) {
            if ((num & lowbit) > 0) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }
        return result;
    }
}