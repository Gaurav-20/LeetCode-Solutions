class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> index;
        for (int i = 0; i < 26; i++) {
            index[order[i]] = i;
        }
        string word1, word2;
        bool isValid = true;
        int len = words.size();
        for (int i = 0; i < len; i++) {
            word1 = words[i];
            for (int j = i + 1; j < len; j++) {
                word2 = words[j];
                int k = 0;
                for (k = 0; k < min(word1.size(), word2.size()); k++) {
                    if (index[word2[k]] < index[word1[k]]) {
                        isValid = false;
                        break;
                    } else if (index[word2[k]] > index[word1[k]]) {
                        break;
                    }
                }
                if (k == word2.size() && k < word1.size()) {
                    isValid = false;
                }
                if (!isValid) {
                    break;
                }
            }
            if (!isValid) {
                break;
            }
        }
        return isValid;
    }
};