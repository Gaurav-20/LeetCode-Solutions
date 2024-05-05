class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) {
            return false;
        }
        int vowels = 0, consonants = 0;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                if (isVowel(ch)) {
                    vowels += 1;
                } else {
                    consonants += 1;
                }
            } else if (ch >= '0' && ch <= '9') {
                // cool
            } else {
                return false;
            }
        }
        return vowels > 0 && consonants > 0;
    }
    
    public boolean isVowel(char c) {
        char ch = Character.toLowerCase(c);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
}