class Solution {
public:
    int expandFromCenter(string& s, int len, int left, int right) {
        while (left >= 0 && right < len && s[left] == s[right])
            left--, right++;

        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int len = s.size();
        int maxLength = 1;
        int resIndex = 0;
        
        for (int i = 0; i < len - 1; i++) {
            int len1 = expandFromCenter(s, len, i, i); 
            // case if longest palindrome is odd length
            int len2 = expandFromCenter(s, len, i, i + 1); 
            // case if longest palindrome is even length
            if (len1 > len2 && len1 > maxLength)
                resIndex = i, maxLength = len1;
            if (len2 > len1 && len2 > maxLength)
                resIndex = i, maxLength = len2;
        }

        string ans = "";
        if (maxLength & 1)
            for (int i = resIndex - maxLength / 2; i < resIndex + (maxLength + 1) / 2; i++)
                ans += s[i];
        else
            for (int i = resIndex - (maxLength - 1) / 2; i <= resIndex + (maxLength + 1) / 2; i++)
                ans += s[i];
        return ans;
    }
};