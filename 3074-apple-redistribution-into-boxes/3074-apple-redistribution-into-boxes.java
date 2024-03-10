class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int totalApples = Arrays.stream(apple).sum(), len = capacity.length;
        Arrays.sort(capacity);
        for (int i = len - 1; i >= 0; i--) {
            totalApples -= capacity[i];
            if (totalApples <= 0) {
                return len - i;
            }
        }
        return len;
    }
}