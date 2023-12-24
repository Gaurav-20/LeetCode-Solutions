class Solution {
    public boolean canConvertString(String s, String t, int k) {
        if (s.length() != t.length()) {
            return false;
        }
        int n = s.length();
        int[] vec = new int[26];
        for (int i = 0; i < n; i++) {
            int sIdx = s.charAt(i) - 'a';
            int tIdx = t.charAt(i) - 'a';
            if (sIdx == tIdx) {
                continue;
            }
            int diff = (tIdx - sIdx + 26) % 26;
            vec[diff] += 1;
        }
        for (int i = 0; i < 26; i++) {
            if (i + (vec[i] - 1) * 26 > k) {
                return false;
            }
        }
        return true;
    }
}