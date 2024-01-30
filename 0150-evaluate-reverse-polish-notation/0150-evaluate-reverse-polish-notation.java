class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String token : tokens) {
            if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
                Integer right = stack.pop();
                Integer left = stack.pop();
                if (token.equals("+")) {
                    stack.add(left + right);
                } else if (token.equals("-")) {
                    stack.add(left - right);
                } else if (token.equals("*")) {
                    stack.add(left * right);
                } else {
                    stack.add(left / right);
                }
            } else {
                stack.add(Integer.valueOf(token));
            }
        }
        return stack.peek();
    }
}