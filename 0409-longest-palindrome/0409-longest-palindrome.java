class Solution {
    public int longestPalindrome(String s) {
        int[] freq = new int[100];
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'A'] += 1;
        }
        int result = 0;
        boolean oddChoosen = false;
        for (int i = 0; i < 100; i++) {
            result += freq[i];
            if (freq[i] % 2 == 1) {
                result -= (oddChoosen ? 1 : 0);
                oddChoosen = true;
            }
        }
        return result;
    }
}