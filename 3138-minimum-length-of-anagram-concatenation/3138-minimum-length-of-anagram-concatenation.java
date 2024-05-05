class Solution {
    public int minAnagramLength(String s) {
        int[] freq = new int[26];
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a'] += 1;
        }
        int gcd = 0;
        for (int i = 0; i < 26; i++) {
            gcd = getGcd(gcd, freq[i]);
        }
        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += freq[i] / gcd;
        }
        return result;
    }
    
    public int getGcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return getGcd(b, a % b);
    }
}