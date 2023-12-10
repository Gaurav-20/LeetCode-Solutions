class Solution {
    public static String vowels = "aeiou";
    
    public int maxVowels(String s, int k) {
        int currVowelCount = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s.charAt(i))) {
                currVowelCount++;
            }
        }
        int maxVowelCount = currVowelCount;
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) {
                currVowelCount++;
            }
            if (isVowel(s.charAt(i - k))) {
                currVowelCount--;
            }
            maxVowelCount = Math.max(maxVowelCount, currVowelCount);
            if (maxVowelCount == k) {
                return k;
            }
        }
        return maxVowelCount;
    }
    
    public boolean isVowel(char c) {
        return vowels.indexOf(c) != -1;
    }
}