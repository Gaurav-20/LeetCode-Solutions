class Solution {
    public int maxOperations(int[] nums, int k) {
        Arrays.sort(nums);
        int low = 0, high = nums.length - 1, result = 0;
        while (low < high) {
            if (nums[low] + nums[high] == k) {
                low++;
                high--;
                result++;
            } else if (nums[low] + nums[high] < k) {
                low++;
            } else {
                high--;
            }
        }
        return result;
    }
}