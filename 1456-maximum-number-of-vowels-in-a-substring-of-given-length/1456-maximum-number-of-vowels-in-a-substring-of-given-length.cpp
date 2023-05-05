class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    int maxVowels(string s, int k) {
        int n = s.size(), vowels = 0;
        for (int i = 0; i < k; i++) {
            if  (isVowel(s[i])) {
                vowels++;
            }
        }
        int res = vowels;
        for (int i = k; i < n; i++) {
            if (isVowel(s[i - k])) {
                vowels--;
            }
            if (isVowel(s[i])) {
                vowels++;
            }
            res = max(res, vowels);
        }
        return res;
    }
};