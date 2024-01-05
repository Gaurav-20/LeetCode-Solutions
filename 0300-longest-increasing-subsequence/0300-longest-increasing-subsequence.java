class Solution {
    public int lengthOfLIS(int[] nums) {
        List<Integer> lis = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int size = lis.size();
            if (size == 0 || lis.get(size - 1) < nums[i]) {
                lis.add(nums[i]);
            } else {
                insertAtCorrectPosition(lis, nums[i]);
            }
        }
        return lis.size();
    }
    
    public void insertAtCorrectPosition(List<Integer> lis, int num) {
        int low = 0, high = lis.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (lis.get(mid) >= num) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        lis.set(low, num);
    }
}