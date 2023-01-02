class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.size();
        if (len == 1) {
            return true;
        }
        bool isFirstLetterCapital = word[0] >= 'A' && word[0] <= 'Z';
        if (isFirstLetterCapital) {
            bool isSecondLetterCapital = word[1] >= 'A' && word[1] <= 'Z';
            if (isSecondLetterCapital) {
                for (int i = 2; i < len; i++) {
                    if (word[i] >= 'a' && word[i] <= 'z') {
                        return false;
                    }
                }
            } else {
                for (int i = 2; i < len; i++) {
                    if (word[i] >= 'A' && word[i] <= 'Z') {
                        return false;
                    }
                }
            }
        } else {
            for (int i = 1; i < len; i++) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    return false;
                }
            }
        }
        return true;
    }
};