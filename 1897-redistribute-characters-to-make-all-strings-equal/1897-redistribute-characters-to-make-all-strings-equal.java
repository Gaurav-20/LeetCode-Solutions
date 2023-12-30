class Solution {
    public boolean makeEqual(String[] words) {
        int[] freq = new int[26];
        for (String word : words) {
            for (int i = 0; i < word.length(); i++) {
                freq[word.charAt(i) - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] % words.length != 0) {
                return false;
            }
        }
        return true;
    }
}