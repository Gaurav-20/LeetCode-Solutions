class Solution {
    public boolean checkValidString(String s) {
        int open = 0;
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '*') {
                open += 1;
            } else {
                open -= 1;
                if (open < 0) {
                    return false;
                }
            }
        }
        open = 0;
        for (int i = arr.length - 1; i >= 0; i--) {
            if (s.charAt(i) == ')' || s.charAt(i) == '*') {
                open += 1;
            } else {
                open -= 1;
                if (open < 0) {
                    return false;
                }
            }
        }
        return true;
    }
}