class Solution {
    public int minimumLength(String s) {
        int low = 0, high = s.length() - 1;
        while (low < high && s.charAt(low) == s.charAt(high)) {
            char curr = s.charAt(low);
            while (low <= high && s.charAt(low) == curr) {
                low++;
            }
            while (low <= high && s.charAt(high) == curr) {
                high--;
            }
        }
        return high - low + 1;
    }
}