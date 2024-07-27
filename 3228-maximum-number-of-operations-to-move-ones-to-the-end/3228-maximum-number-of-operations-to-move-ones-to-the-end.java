class Solution {
    public int maxOperations(String s) {
        int result = 0, ones = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) == '1') {
                ones += 1;
            }
            if (s.charAt(i - 1) == '1' && s.charAt(i) == '0') {
                result += ones;
            }
        }
        return result;
    }
}