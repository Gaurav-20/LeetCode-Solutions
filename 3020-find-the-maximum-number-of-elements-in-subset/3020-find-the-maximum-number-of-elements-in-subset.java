class Solution {
    public int maximumLength(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }
        int result = 1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                int ans = map.get(nums[i]);
                if (ans % 2 == 0) {
                    ans -= 1;
                }
                result = Math.max(result, ans);
                continue;
            } else if (map.get(nums[i]) >= 2) {
                int curr = nums[i];
                int ans = 1;
                while (true) {
                    if (curr >= 100000) {
                        break;
                    }
                    curr = (int) Math.pow(curr, 2);                
                    if (map.containsKey(curr)) {
                        ans++;
                        if (map.get(curr) == 1) {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                ans = (ans - 1) * 2 + 1;
                result = Math.max(result, ans);
            }
        }
        return result;
    }
}