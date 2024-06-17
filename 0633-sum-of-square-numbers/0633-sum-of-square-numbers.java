class Solution {
    public boolean judgeSquareSum(int c) {
        if (c < 3) {
            return true;
        }
        long a = 0, b = (long) Math.sqrt(c);
        while (a <= b) {
            long curr = a * a + b * b;
            if (curr == c) {
                return true;
            } else if (curr < c) {
                a++;
            } else {
                b--;
            }
        }
        return false;
    }
}