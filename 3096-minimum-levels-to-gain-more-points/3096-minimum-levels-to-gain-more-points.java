class Solution {
    public int minimumLevels(int[] possible) {
        int n = possible.length, left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            if (possible[i] == 0) {
                possible[i] = -1;
            }
            right += possible[i];
        }
        
        for (int i = 0; i < n - 1; i++) {
            left += possible[i];
            right -= possible[i];
            if (left > right) {
                return i + 1;
            }
        }
        return -1;
    }
}