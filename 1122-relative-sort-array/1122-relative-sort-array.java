class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] result = new int[arr1.length];
        Map<Integer, Integer> map = new HashMap<>();

        for (int num : arr1) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        int index = 0;

        for (int num : arr2) {
            int count = map.get(num);
            while (count-- > 0) {
                result[index++] = num;
            }
            map.remove(num);
        }

        int remainingIndex = index;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int num = entry.getKey();
            int count = entry.getValue();
            while (count-- > 0) {
                result[index++] = num;
            }
        }

        Arrays.sort(result, remainingIndex, result.length);
        return result;
    }
}