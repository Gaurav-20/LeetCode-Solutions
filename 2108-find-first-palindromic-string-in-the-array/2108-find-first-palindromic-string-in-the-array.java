class Solution {
    public String firstPalindrome(String[] words) {
        for (String word : words) {
            if (isPalindromic(word)) {
                return word;
            }
        }
        return "";
    }
    
    public boolean isPalindromic(String word) {
        int low = 0, high = word.length() - 1;
        while (low < high) {
            if (word.charAt(low) != word.charAt(high)) {
                return false;
            }
            low += 1;
            high -= 1;
        }
        return true;
    }
}