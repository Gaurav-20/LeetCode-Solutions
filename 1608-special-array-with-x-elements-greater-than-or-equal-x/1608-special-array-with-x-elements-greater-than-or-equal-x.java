class Solution {
    public int specialArray(int[] nums) {
        for (int x = 1; x <= nums.length; x++) {
            int counter = 0;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] >= x) {
                    counter += 1;
                }
            }
            if (counter == x) {
                return x;
            }
        }
        return -1;
    }
}