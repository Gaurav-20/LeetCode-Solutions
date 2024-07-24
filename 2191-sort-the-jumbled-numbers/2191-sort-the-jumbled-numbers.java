class Solution {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int n = nums.length;
        Integer[] arr = new Integer[n];
        Map<Integer, Integer> mapped = new HashMap<>();
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
            mapped.put(arr[i], getMappedValue(arr[i], mapping));
        }
        Arrays.sort(arr, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return mapped.get(a) - mapped.get(b);
            }
        });
        return Arrays.stream(arr).mapToInt(Integer::intValue).toArray();
    }
    
    public int getMappedValue(int num, int[] mapping) {
        String str = String.valueOf(num);
        StringBuilder builder = new StringBuilder();
        for (char ch: str.toCharArray()) {
            builder.append(mapping[ch - '0']);
        }
        return Integer.valueOf(builder.toString());
    }
}