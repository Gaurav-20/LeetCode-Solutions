class Solution {
    public int incremovableSubarrayCount(int[] nums) {
        int n = nums.length, result = 1; // for 1 empty array
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                List<Integer> list = new ArrayList<>();
                for (int k = 0; k < i; k++) {
                    list.add(nums[k]);
                }
                for (int k = j + 1; k < n; k++) {
                    list.add(nums[k]);
                }
                result += (isIncreasing(list) == true) ? 1 : 0;
            }
        }
        return result;
    }
    
    public boolean isIncreasing(List<Integer> list) {
        if (list.size() == 0) {
            return false;
        }
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i) <= list.get(i - 1)) {
                return false;
            }
        }
        return true;
    }
}