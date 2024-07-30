class Solution {
    public boolean checkString(String s) {
        boolean isBFound = false;
        for (char c: s.toCharArray()) {
            if (c == 'a' && isBFound) {
                return false;
            }
            if (c == 'b') {
                isBFound = true;
            }
        }
        return true;
    }
}