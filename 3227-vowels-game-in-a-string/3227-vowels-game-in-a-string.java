class Solution {
    public boolean doesAliceWin(String s) {
        int vowels = 0;
        for (char ch: s.toCharArray()) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels += 1;
            }
        }
        if (vowels % 2 == 1) {
            return true;
        }
        if (vowels == 0) {
            return false;
        }
        return true;
    }
}