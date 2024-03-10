class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        Map<Integer, Boolean> map = new HashMap<>();
        for (int i = 0; i < n1; i++) {
            map.putIfAbsent(nums1[i], true);
        }
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n2; i++) {
            if (map.containsKey(nums2[i])) {
                map.remove(nums2[i]);
                res.add(nums2[i]);
            }
        }
        return res.stream().mapToInt(i -> i).toArray();
    }
}