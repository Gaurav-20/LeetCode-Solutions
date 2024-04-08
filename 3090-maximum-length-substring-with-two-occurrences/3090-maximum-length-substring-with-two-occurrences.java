class Solution {
    public int maximumLengthSubstring(String s) {
        int[] freq = new int[26];
        int result = 1;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            char ch = s.charAt(right);
            freq[ch - 'a'] += 1;
            while (freq[ch - 'a'] > 2) {
                freq[s.charAt(left) - 'a'] -= 1;
                left += 1;
            }
            result = Math.max(result, right - left + 1);
        }
        return result;
    }
}