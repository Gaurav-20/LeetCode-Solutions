class Solution {
    public String customSortString(String order, String s) {
        int[] freq = new int[26];
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a'] += 1;
        }
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < order.length(); i++) {
            char curr = order.charAt(i);
            for (int j = 0; j < freq[curr - 'a']; j++) {
                builder.append(curr);
            }
            freq[curr - 'a'] = 0;
        }
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                builder.append((char) (i + 'a'));
                freq[i] -= 1;
            }
        }
        return builder.toString();
    }
}