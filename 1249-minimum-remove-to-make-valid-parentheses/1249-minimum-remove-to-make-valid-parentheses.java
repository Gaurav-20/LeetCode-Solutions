class Solution {
    public String minRemoveToMakeValid(String s) {
        char[] charArray = s.toCharArray();
        int open = 0;
        for (int i = 0; i < charArray.length; i++) {
            char ch = charArray[i];
            if (ch == '(') {
                open += 1;
            } else if (ch == ')') {
                if (open == 0) {
                    charArray[i] = '*';
                } else {
                    open -= 1;
                }
            }
        }
        open = 0;
        for (int i = charArray.length - 1; i >= 0; i--) {
            char ch = charArray[i];
            if (ch == '(') {
                if (open == 0) {
                    charArray[i] = '*';
                } else {
                    open -= 1;
                }
            } else if (ch == ')') {
                open += 1;
            }
        }
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < charArray.length; i++) {
            if (charArray[i] != '*') {
                builder.append(charArray[i]);
            }
        }
        return builder.toString();
    }
}