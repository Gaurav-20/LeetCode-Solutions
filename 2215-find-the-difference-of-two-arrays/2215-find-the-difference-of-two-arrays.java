class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> result = new ArrayList<>();
        result.add(getDifference(nums1, nums2));
        result.add(getDifference(nums2, nums1));
        return result;
    }
    
    public List<Integer> getDifference(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums2.length; i++) {
            set.add(nums2[i]);
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums1.length; i++) {
            if (!set.contains(nums1[i])) {
                list.add(nums1[i]);
            }
            set.add(nums1[i]);
        }
        return list;
    }
}