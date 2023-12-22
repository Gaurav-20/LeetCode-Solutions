class Solution {
    public int maxScore(String s) {
        int n = s.length();
        int[] zerosCount = new int[n];
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {
                zerosCount[i] = 1;
            }
            if (i > 0) {
                zerosCount[i] += zerosCount[i - 1];
            }
        }
        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            int zerosToLeft = zerosCount[i];
            int onesToRight = n - i - 1 - (zerosCount[n - 1] - zerosCount[i]);
            result = Math.max(result, zerosToLeft + onesToRight);
        }
        return result;
    }
}