class Solution {
    public int countSubstrings(String s) {
        int len = s.length(), result = 0;
        for (int i = 0; i < len; i++) {
            result += count(s, i, i, len);
            result += count(s, i, i + 1, len);
        }
        return result;
    }
    
    public int count(String s, int left, int right, int len) {
        int res = 0;
        while (left >= 0 && right < len && s.charAt(left) == s.charAt(right)) {
            res++;
            left--;
            right++;
        }
        return res;
    }
}