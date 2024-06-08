class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int sum = 0, prev = 0;
        Set<Integer> modk = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            int mod = sum % k;
            if (modk.contains(mod)) {
                return true;
            }
            modk.add(prev);
            prev = mod;
        }
        return false;
    }
}