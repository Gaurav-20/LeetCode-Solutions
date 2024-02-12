class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int majority = nums[0];
        int counter = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == majority) {
                counter += 1;
            } else {
                counter -= 1;
            }
            if (counter == 0) {
                majority = nums[i];
                counter += 1;
            }
        }
        return majority;
    }
}