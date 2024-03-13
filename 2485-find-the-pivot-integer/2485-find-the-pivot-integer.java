class Solution {
    public int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
            if (sum == totalSum) {
                return i;
            }
            totalSum -= i;
        }
        return -1;
    }
}