class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxQueue = new ArrayDeque<>();
        Deque<Integer> minQueue = new ArrayDeque<>();
        int j = 0, result = 0;
        for (int i = 0; i < nums.length; i++) {
            while (!maxQueue.isEmpty() && nums[i] > maxQueue.peekLast()) {
                maxQueue.pollLast();
            }
            maxQueue.addLast(nums[i]);
            while (!minQueue.isEmpty() && nums[i] < minQueue.peekLast()) {
                minQueue.pollLast();
            }
            minQueue.addLast(nums[i]);
            if (maxQueue.peekFirst() - minQueue.peekFirst() > limit){
                if (nums[j] == maxQueue.peekFirst()) {
                    maxQueue.pollFirst();
                }
                if (nums[j] == minQueue.peekFirst()) {
                    minQueue.pollFirst();
                }
                j += 1;
            }
            result = Math.max(result, i - j + 1);
        }
        return result;
    }
}