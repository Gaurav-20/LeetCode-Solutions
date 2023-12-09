class Solution {
    public String mergeAlternately(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int i = 0, j = 0;
        String result = new String("");
        while (i < m && j < n) {
            result += word1.charAt(i);
            result += word2.charAt(j);
            i++;
            j++;
        }
        while (i < m) {
            result += word1.charAt(i);
            i++;
        }
        while (j < n) {
            result += word2.charAt(j);
            j++;
        }
        return result;
    }
}