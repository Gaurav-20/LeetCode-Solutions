class Solution {
    public int minimumChairs(String s) {
        int depth = 0, maxDepth = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'E') {
                depth += 1;
            } else {
                depth -= 1;
            }
            maxDepth = Math.max(maxDepth, depth);
        }
        return maxDepth;
    }
}