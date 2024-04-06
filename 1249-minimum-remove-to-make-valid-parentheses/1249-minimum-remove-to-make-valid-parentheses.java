class Solution {
    public String minRemoveToMakeValid(String s) {
        char[] charArray = s.toCharArray();
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < charArray.length; i++) {
            char ch = charArray[i];
            if (ch == '(') {
                stack.add(ch);
            } else if (ch == ')') {
                if (stack.isEmpty()) {
                    charArray[i] = '*';
                } else {
                    stack.pop();
                }
            }
        }
        stack.clear();
        for (int i = charArray.length - 1; i >= 0; i--) {
            char ch = charArray[i];
            if (ch == '(') {
                if (stack.isEmpty()) {
                    charArray[i] = '*';
                } else {
                    stack.pop();
                }
            } else if (ch == ')') {
                stack.add(ch);
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