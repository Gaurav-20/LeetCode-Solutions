class Solution {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int n = nums.length;
        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
        }
        Arrays.sort(arr, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                Integer aMapped = getMappedValue(a, mapping);
                Integer bMapped = getMappedValue(b, mapping);
                return aMapped - bMapped;
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