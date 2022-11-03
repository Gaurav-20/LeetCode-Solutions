class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int largestPalindromeLength = 0;
        int count[26][26] = { 0 };
        for (string word : words) {
            int x = word[0] - 'a', y = word[1] - 'a';
            if (count[y][x]) {
                largestPalindromeLength += 4;
                count[y][x]--;
            } else {
                count[x][y]++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (count[i][i]) {
                largestPalindromeLength += 2;
                break;
            }
        }
        return largestPalindromeLength;
    }
};