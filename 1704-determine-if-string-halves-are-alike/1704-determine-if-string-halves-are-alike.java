class Solution {
    public static String VOWELS = "aeiouAEIOU";
    
    public boolean halvesAreAlike(String s) {
        int count = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            char ch = s.charAt(i);
            if (VOWELS.indexOf(ch) != -1) {
                count += 1;
            }
        }
        for (int i = s.length() / 2; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (VOWELS.indexOf(ch) != -1) {
                count -= 1;
            }
        }
        return count == 0;
    }
}