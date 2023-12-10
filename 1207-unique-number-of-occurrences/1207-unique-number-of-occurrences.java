class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (map.get(arr[i]) == null) {
                map.put(arr[i], 1);
            } else {
                map.put(arr[i], map.get(arr[i]) + 1);
            }
        }
        Set<Integer> set = new HashSet<>();
        for (Integer entry : map.values()) {
            set.add(entry);
        }
        return map.size() == set.size();
    }
}