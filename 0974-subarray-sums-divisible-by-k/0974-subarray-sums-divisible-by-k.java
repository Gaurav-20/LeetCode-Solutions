class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int[] freqCount = new int[k];
        freqCount[0] = 1;
        int prefix = 0, result = 0;
        for (int num : nums) {
            prefix = (prefix + num % k + k) % k;
            result += freqCount[prefix];
            freqCount[prefix] += 1;
        }
        return result;
    }
}