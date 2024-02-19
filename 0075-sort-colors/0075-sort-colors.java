class Solution {
     public void sortColors(int[] nums) {
        int low = 0;
        int high = nums.length - 1;
        int current = 0;

        while (current <= high) {
            if (nums[current] == 0) {
                swap(nums, low, current);
                low++;
                current++; 
            } else if (nums[current] == 2) {
                swap(nums, high, current);
                high--;
            } else {
                current++;
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}