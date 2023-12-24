class Solution {
    public int minOperations(String s) {
        int oddOnes = 0, oddZeros = 0, evenOnes = 0, evenZeros = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (i % 2 == 0) {
                if (ch == '0') {
                    evenZeros++;
                } else {
                    evenOnes++;
                }
            } else {
                if (ch == '0') {
                    oddZeros++;
                } else {
                    oddOnes++;
                }
            }
        }
        return Math.min(evenZeros + oddOnes, evenOnes + oddZeros);
    }
}