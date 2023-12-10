class Solution {
    public String removeStars(String s) {
        StringBuilder builder = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == '*') {
                builder.setLength(builder.length() - 1);
            } else {
                builder.append(c);
            }
        }
        return builder.toString();
    }
}