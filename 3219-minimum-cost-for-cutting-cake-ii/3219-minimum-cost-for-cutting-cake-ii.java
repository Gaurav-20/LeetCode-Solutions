class Solution {
    public long minimumCost(int m, int n, int[] horizontalCuts, int[] verticalCuts) {
        long result = 0;
        Integer[] horizontalCut = Arrays.stream(horizontalCuts).boxed().toArray(Integer[]::new);
        Integer[] verticalCut = Arrays.stream(verticalCuts).boxed().toArray(Integer[]::new);
        Arrays.sort(horizontalCut, Collections.reverseOrder());
        Arrays.sort(verticalCut, Collections.reverseOrder());
        int i = 0, j = 0;
        while (i < m - 1 && j < n - 1) {
            if (horizontalCut[i] >= verticalCut[j]) {
                result += (long) horizontalCut[i] * (j + 1);
                i += 1;
            } else {
                result += (long) verticalCut[j] * (i + 1);
                j += 1;
            }
        }
        while (i < m - 1) {
            result += (long) horizontalCut[i] * (j + 1);
            i += 1;
        }
        while (j < n - 1) {
            result += (long) verticalCut[j] * (i + 1);
            j += 1;
        }
        return result;
    }
}