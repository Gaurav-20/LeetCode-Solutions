class Solution {
    public static String vowels = "aeiouAEIOU";
    
    public String reverseVowels(String s) {
        char[] charArray = s.toCharArray();
        int left = 0, right = charArray.length - 1;
        while (left < right) {
            while (left < right && !isVowel(charArray[left])) {
                left++;
            }
            while (left < right && !isVowel(charArray[right])) {
                right--;
            }
            char temp = charArray[left];
            charArray[left] = charArray[right];
            charArray[right] = temp;
            left++;
            right--;
        }
        return String.valueOf(charArray);
    }
    
    public boolean isVowel(char c) {
        return vowels.indexOf(c) != -1;
    }
}