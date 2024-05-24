class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int len = words.length;
        int[] freqAvailable = new int[26];
        for (char letter : letters) {
            freqAvailable[letter - 'a'] += 1;
        }
        int result = 0;
        for (int i = 1; i < (1 << len); i++) {
            List<String> wordList = new ArrayList<>();
            for (int j = 0; j < len; j++) {
                if (((i >> j) & 1) == 1) {
                    wordList.add(words[j]);
                }
            }
            int[] freq = freqAvailable.clone();
            result = Math.max(result, solve(wordList, freq, score));
        }
        return result;
    }
    
    public int solve(List<String> wordList, int[] freq, int[] score) {
        int result = 0;
        for (String word: wordList) {
            for (int i = 0; i < word.length(); i++) {
                int charIdx = word.charAt(i) - 'a';
                if (freq[charIdx] == 0) {
                    return 0;
                } else {
                    freq[charIdx] -= 1;
                    result += score[charIdx];
                }
            }
        }
        return result;
    }
}