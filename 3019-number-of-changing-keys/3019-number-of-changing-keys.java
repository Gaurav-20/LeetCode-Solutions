class Solution {
    public int countKeyChanges(String str) {
        String s = str.toLowerCase();
        char prev = s.charAt(0);
        int result = 0;
        for (int i = 1; i < s.length(); i++) {
            char curr = s.charAt(i);
            if (curr != prev) {
                prev = curr;
                result += 1;
            }
        }
        return result;
    }
}