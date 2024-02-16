class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }
        List<Integer> freqs = new ArrayList<>(map.values());
        Collections.sort(freqs);
        for (int i = 0; i < freqs.size(); i++) {
            if (freqs.get(i) <= k) {
                k -= freqs.get(i);
            } else {
                return freqs.size() - i;
            }
        }
        return 0;
    }
}