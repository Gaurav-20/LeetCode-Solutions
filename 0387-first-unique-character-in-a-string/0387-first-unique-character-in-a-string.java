class Solution {
    public int firstUniqChar(String s) {
        int n = s.length();
        if (n == 0) {
            return -1;
        }
        int[] freq = new int[26];
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            freq[idx]++;
        }
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            if (freq[idx] == 1) {
                return i;
            }
        }
        return -1;
    }
}