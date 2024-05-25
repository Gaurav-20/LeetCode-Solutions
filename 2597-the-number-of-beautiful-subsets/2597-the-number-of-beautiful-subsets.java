class Solution {
    public int result;
    
    public int beautifulSubsets(int[] nums, int k) {
        result = 0;
        solve(nums, 0, k, new ArrayList<>(), new int[3005]);
        return result - 1;
    }
    
    public void solve(int[] nums, int i, int k, List<Integer> list, int[] map) {
        result += 1;
        for (int idx = i; idx < nums.length; idx++) {
            if (map[nums[idx] + k + 1000] > 0) {
                continue;
            }
            if (map[nums[idx] - k + 1000] > 0) {
                continue;
            }
            map[nums[idx] + 1000] += 1;
            list.add(nums[idx]);
            solve(nums, idx + 1, k, list, map);
            map[nums[idx] + 1000] -= 1;
            list.remove(list.size() - 1);
        }
    }
}