class Solution {
    public int numberOfAlternatingGroups(int[] colors) {
        int n = colors.length, result = 0;
        for (int i = 0; i < n; i++) {
            int left = (i + n - 1) % n;
            int right = (i + 1) % n;
            int curr = i % n;
            if (colors[left] != colors[curr] && colors[right] != colors[curr]) {
                result += 1;
            }
        }
        return result;
    }
}