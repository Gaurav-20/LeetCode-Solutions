class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == x) {
                list.add(i);
            }
        }
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int q = queries[i] - 1;
            if (q >= list.size()) {
                result[i] = -1;
            } else {
                result[i] = list.get(q);
            }
        }
        return result;
    }
}