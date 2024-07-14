class Solution {
    public String countOfAtoms(String formula) {
        Stack<Map<String, Integer>> stack = new Stack<>();
        stack.push(new HashMap<>());
        int i = 0, n = formula.length();
        while (i < n) {
            if (formula.charAt(i) == '(') {
                stack.push(new HashMap<>());
                i += 1;
            } else if (formula.charAt(i) == ')') {
                Map<String, Integer> curr = stack.pop();
                i += 1;
                StringBuilder mult = new StringBuilder();
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    mult.append(formula.charAt(i));
                    i += 1;
                }
                if (mult.length() > 0) {
                    Integer multiplier = Integer.valueOf(mult.toString());
                    for (Map.Entry<String, Integer> entry : curr.entrySet()) {
                        String element = entry.getKey();
                        Integer count = entry.getValue();
                        curr.put(element, count * multiplier);
                    }
                }
                for (Map.Entry<String, Integer> entry : curr.entrySet()) {
                    String element = entry.getKey();
                    Integer count = entry.getValue();
                    stack.peek().put(element, stack.peek().getOrDefault(element, 0) + count);
                }
            } else {
                StringBuilder currElement = new StringBuilder();
                currElement.append(formula.charAt(i));
                i += 1;
                while (i < n && Character.isAlphabetic(formula.charAt(i)) && Character.isLowerCase(formula.charAt(i))) {
                    currElement.append(formula.charAt(i));
                    i += 1;
                }
                StringBuilder counter = new StringBuilder();
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    counter.append(formula.charAt(i));
                    i += 1;
                }
                String currElem = currElement.toString();
                Integer count = counter.length() > 0 ? Integer.valueOf(counter.toString()) : 1;
                stack.peek().put(currElem, stack.peek().getOrDefault(currElem, 0) + count);
            }
        }
        Map<String, Integer> map = new TreeMap<>(stack.pop());
        StringBuilder result = new StringBuilder();
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            String element = entry.getKey();
            Integer count = entry.getValue();
            result.append(element);
            if (count > 1) {
                result.append(String.valueOf(count));
            }
        }
        return result.toString();
    }
}