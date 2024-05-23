class Solution {
    public int result;
    
    public int beautifulSubsets(int[] nums, int k) {
        result = 0;
        solve(nums, 0, k, new ArrayList<>(), new HashMap<>());
        return result - 1;
    }
    
    public void solve(int[] nums, int i, int k, List<Integer> list, Map<Integer, Integer> map) {
        result += 1;
        for (int idx = i; idx < nums.length; idx++) {
            if (map.containsKey(nums[idx] + k) && map.get(nums[idx] + k) > 0) {
                continue;
            }
            if (map.containsKey(nums[idx] - k) && map.get(nums[idx] - k) > 0) {
                continue;
            }
            map.put(nums[idx], map.getOrDefault(nums[idx], 0) + 1);
            list.add(nums[idx]);
            solve(nums, idx + 1, k, list, map);
            map.put(nums[idx], map.get(nums[idx]) - 1);
            list.remove(list.size() - 1);
        }
    }
}