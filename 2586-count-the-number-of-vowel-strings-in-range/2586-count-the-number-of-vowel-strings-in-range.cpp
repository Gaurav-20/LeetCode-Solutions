bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

class Solution {
public:
    
    int vowelStrings(vector<string>& words, int left, int right) {
        int res = 0;
        for (int i = left; i <= right; i++) {
            string word = words[i];
            res += isVowel(word[0]) && isVowel(word.back());
        }
        return res;
    }
};