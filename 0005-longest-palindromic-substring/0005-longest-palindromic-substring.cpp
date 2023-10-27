class Solution {
public:
    pair<int, int> expandFromBetween(string s, int left, int right, int len) {
        while (left >= 0 && right < len && s[left] == s[right]) {
            left--;
            right++;
        }
        return { right - left - 1, left + 1 };
    }
    
    string longestPalindrome(string s) {
        int len = s.size();
        int maxLen = 1;
        int maxLenStartIndex = 0;
        for (int i = 0; i < len - 1; i++) {
            auto [oddLen, oddLenStartIndex] = expandFromBetween(s, i, i, len);
            auto [evenLen, evenLenStartIndex] = expandFromBetween(s, i, i + 1, len);
            if (maxLen < oddLen) {
                maxLen = oddLen;
                maxLenStartIndex = oddLenStartIndex;
            }
            if (maxLen < evenLen) {
                maxLen = evenLen;
                maxLenStartIndex = evenLenStartIndex;
            }
        }
        string res = "";
        for (int i = maxLenStartIndex; i < maxLenStartIndex + maxLen; i++) {
            res += s[i];
        }
        return res;
    }
};