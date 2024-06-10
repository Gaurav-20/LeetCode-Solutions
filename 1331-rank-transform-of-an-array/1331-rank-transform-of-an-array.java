class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;
        int[] result = arr.clone();
        Arrays.sort(result);
        Map<Integer, Integer> map = new HashMap<>();
        int rank = 1;
        for (int i = 0; i < n; i++) {
            if (!map.containsKey(result[i])) {
                map.put(result[i], rank);
                rank += 1;
            }
        }
        for (int i = 0; i < n; i++) {
            result[i] = map.get(arr[i]);
        }
        return result;
    }
}