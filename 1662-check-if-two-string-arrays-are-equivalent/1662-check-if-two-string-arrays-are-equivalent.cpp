class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0; // pointer to each word
        int m = 0, n = 0; // pointer to each char in word
        int len1 = word1.size(), len2 = word2.size();
        while (i < len1 && j < len2) {
            if (word1[i][m++] != word2[j][n++]) {
                return false;
            }
            if (m == word1[i].size()) {
                i++, m = 0;
            }
            if (n == word2[j].size()) {
                j++, n = 0;
            }
        }
        return (i == len1) && (j == len2);
    }
};