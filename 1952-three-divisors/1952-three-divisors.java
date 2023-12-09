class Solution {
    public boolean isThree(int n) {
        int numDivisors = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                numDivisors += 2;
                if (i * i == n) {
                    numDivisors -= 1;
                }
            }
        }
        return numDivisors == 3;
    }
}