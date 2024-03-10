class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < n1; i++) {
            set.add(nums1[i]);
        }
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n2; i++) {
            if (set.contains(nums2[i])) {
                set.remove(nums2[i]);
                res.add(nums2[i]);
            }
        }
        return res.stream().mapToInt(i -> i).toArray();
    }
}