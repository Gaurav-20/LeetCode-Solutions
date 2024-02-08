class Solution {
    public boolean isSquare(int n) {
        return Math.sqrt(n) == (int) Math.sqrt(n);
    }
    
    public int numSquares(int n) {
        // Based on Lagrange's Four Square theorem, there
        // are only 4 possible results: 1, 2, 3, 4.
        // If n is a perfect square, return 1.
        if (isSquare(n)) {
            return 1;
        }
        // The result is 4 if and only if n can be written in the 
        // form of 4^k * (8*m + 7) as per the
        // Legendre's three-square theorem
        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }
        // Check whether the result is possible with 2 nums
        int sqrtN = (int) Math.sqrt(n);
        for (int i = 1; i <= sqrtN; i++) {
            if (isSquare(n - (i * i))) {
                return 2;
            }
        }
        return 3;
    }
}