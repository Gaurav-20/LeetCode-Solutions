class Solution {
public:
    vector<int> expandFromBetween(string s, int left, int right, int len) {
        // returns { length of the palindrome found, start index of the palindrome }
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
            vector<int> odd = expandFromBetween(s, i, i, len);
            vector<int> even = expandFromBetween(s, i, i + 1, len);
            if (maxLen < odd[0]) {
                maxLen = odd[0];
                maxLenStartIndex = odd[1];
            }
            if (maxLen < even[0]) {
                maxLen = even[0];
                maxLenStartIndex = even[1];
            }
        }
        string res = "";
        for (int i = maxLenStartIndex; i < maxLenStartIndex + maxLen; i++) {
            res += s[i];
        }
        return res;
    }
};