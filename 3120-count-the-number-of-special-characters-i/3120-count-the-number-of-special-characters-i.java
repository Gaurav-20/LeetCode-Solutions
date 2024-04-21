class Solution {
    public int numberOfSpecialChars(String word) {
        boolean[] lower = new boolean[26];
        boolean[] upper = new boolean[26];
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                lower[ch - 'a'] = true;
            }
            if (ch >= 'A' && ch <= 'Z') {
                upper[ch - 'A'] = true;
            }
        }
        int result = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) {
                result += 1;
            }
        }
        return result;
    }
}