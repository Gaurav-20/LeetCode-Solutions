class Solution {
    public int minPatches(int[] nums, int n) {
        int patches = 0;
        int i = 0;
        long miss = 1;
        while (miss <= n) {
            if (i < nums.length && nums[i] <= miss) {
                miss += nums[i];
                i += 1;
            } else {
                miss += miss;
                patches += 1;
            }
        }
        return patches;
    }
}