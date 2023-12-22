class Solution {
    public int maxScore(String s) {
        int n = s.length();
        int onesToRight = 0, zerosToLeft = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                onesToRight += 1;
            }
        }
        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == '0') {
                zerosToLeft++;
            } else {
                onesToRight--;
            }
            result = Math.max(result, zerosToLeft + onesToRight);
        }
        return result;
    }
}