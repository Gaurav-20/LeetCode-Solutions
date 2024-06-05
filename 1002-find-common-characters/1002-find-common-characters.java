class Solution {
    public List<String> commonChars(String[] words) {
        int[] freq = new int[26];
        Arrays.fill(freq, 1000000);
        for (String word : words) {
            int[] w = new int[26];
            for (char c : word.toCharArray()) {
                w[c - 'a'] += 1;
            }
            for (int i = 0; i < 26; i++) {
                freq[i] = Math.min(freq[i], w[i]);
            }
        }
        List<String> result = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freq[i]; j++) {
                result.add(String.valueOf((char)(i + 'a')));
            }
        }
        return result;
    }
}