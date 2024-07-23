class Solution {
    public int[] frequencySort(int[] nums) {
        int n = nums.length;
        Integer[] result = new Integer[n];
        Map<Integer, Integer> freq = new HashMap<>();
        for (int i = 0; i < n; i++) {
            result[i] = nums[i];
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
        }
        Arrays.sort(result, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                int freqA = freq.get(a), freqB = freq.get(b);
                if (freqA == freqB) {
                    return b - a;
                } else {
                    return freqA - freqB;
                }
            }
        });
        return Arrays.stream(result).mapToInt(Integer::intValue).toArray();
    }
}