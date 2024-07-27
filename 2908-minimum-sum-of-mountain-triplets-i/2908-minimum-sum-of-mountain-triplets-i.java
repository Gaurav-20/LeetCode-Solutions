class Solution {
    public int minimumSum(int[] nums) {
        int n = nums.length, result = 1000000;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] < nums[j] && nums[k] < nums[j]) {
                        result = Math.min(result, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        return (result < 1000000) ? result : -1;
    }
}