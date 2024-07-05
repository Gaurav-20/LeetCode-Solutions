class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        return countPairsLessThan(nums, upper) - countPairsLessThan(nums, lower - 1);
    }
    
    public long countPairsLessThan(int[] nums, int target) {
        long count = 0;
        int start = 0, end = nums.length - 1;
        while (start <= end) {
            if (nums[start] + nums[end] > target) {
                end -= 1;
            } else {
                count += end - start;
                start += 1;
            }
        }
        return count;
    }
}