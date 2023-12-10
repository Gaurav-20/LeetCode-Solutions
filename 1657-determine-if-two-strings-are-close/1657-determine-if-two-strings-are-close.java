class Solution {
    public boolean closeStrings(String word1, String word2) {
        int[] w1 = new int[26];
        int[] w2 = new int[26];
        boolean[] w3 = new boolean[26];
        boolean[] w4 = new boolean[26];
        for (int i = 0; i < word1.length(); i++) {
            char c = word1.charAt(i);
            w1[c - 'a']++;
            w3[c - 'a'] = true;
        }
        for (int i = 0; i < word2.length(); i++) {
            char c = word2.charAt(i);
            w2[c - 'a']++;
            w4[c - 'a'] = true;
        }
        Arrays.sort(w1);
        Arrays.sort(w2);
        for (int i = 0; i < 26; i++) {
            if (w1[i] != w2[i] || w3[i] != w4[i]) {
                return false;
            }
        }
        return true;
    }
}