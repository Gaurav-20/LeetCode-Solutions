class Solution {
    public int minOperations(String s) {
        int oddOnes = 0, oddZeros = 0, evenOnes = 0, evenZeros = 0;
        for (int i = 1; i < s.length(); i += 2) {
            if (s.charAt(i) != '1') {
                oddOnes += 1;
            }
            if (s.charAt(i) != '0') {
                oddZeros += 1;
            }
        }
        for (int i = 0; i < s.length(); i += 2) {
            if (s.charAt(i) != '1') {
                evenOnes += 1;
            }
            if (s.charAt(i) != '0') {
                evenZeros += 1;
            }
        }
        return Math.min(evenZeros + oddOnes, evenOnes + oddZeros);
    }
}