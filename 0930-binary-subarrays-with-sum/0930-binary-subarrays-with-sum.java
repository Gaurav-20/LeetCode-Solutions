class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int count = 0;
        Map<Integer, Integer> sumFreq = new HashMap<>();
        sumFreq.put(0, 1);
        int currSum = 0;
        for (int i = 0; i < nums.length; i++) {
            currSum += nums[i];
            count += sumFreq.getOrDefault(currSum - goal, 0);
            sumFreq.put(currSum, sumFreq.getOrDefault(currSum, 0) + 1);
        }
        return count;
    }
}