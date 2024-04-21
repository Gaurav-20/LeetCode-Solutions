class Solution {
    public int numberOfSpecialChars(String word) {
        int[] lower = new int[26];
        int[] upper = new int[26];
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                lower[ch - 'a'] = i + 1;
            }
            if (ch >= 'A' && ch <= 'Z') {
                if (upper[ch - 'A'] == 0) {
                    upper[ch - 'A'] = i + 1;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < 26; i++) {
            if ((lower[i] > 0) && (upper[i] > 0) && (lower[i] < upper[i])) {
                result += 1;
            }
        }
        return result;
    }
}