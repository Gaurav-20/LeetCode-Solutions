class Solution {
    public boolean canAliceWin(int[] nums) {
        int oneDigit = 0, twoDigit = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 10) {
                oneDigit += nums[i];
            } else {
                twoDigit += nums[i];
            }
        }
        return oneDigit != twoDigit;
    }
}