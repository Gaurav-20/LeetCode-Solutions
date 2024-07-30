class Solution {
    public int minimumDeletions(String s) {
        int result = 0, countB = 0;
        for (char c : s.toCharArray()) {
            if (c == 'b') {
                countB += 1;
            } else {
                result = Math.min(result + 1, countB);
            }
        }
        return result;
    }
}