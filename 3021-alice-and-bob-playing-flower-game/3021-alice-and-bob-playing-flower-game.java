class Solution {
    public long flowerGame(int n, int m) {
        if (n < m) {
            return flowerGame(m, n);
        }
        long result = 0;
        int countOfEven = n / 2;
        int countOfOdd = (n + 1) / 2;
        for (int ct = 1; ct <= m; ct++) {
            if (ct % 2 == 1) {
                result += countOfEven;
            } else {
                result += countOfOdd;
            }
        }
        return result;
    }
}