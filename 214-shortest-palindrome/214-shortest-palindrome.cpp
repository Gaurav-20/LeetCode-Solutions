class Solution {
public:
    
    string shortestPalindrome(string s) {
        int n = s.size();
        int leftMost = 0;
        int rightMost = 0;
        int i = 0, start, end;
        while (i < n) {
            start = i;
            while (s[i] == s[start]) {
                i++;
            }
            end = i - 1;
            while (start >= 1 && end < n - 1 && s[start - 1] == s[end + 1]) {
                start--;
                end++;
            }
            if (start == 0 && (end - start) > (rightMost - leftMost)) {
                leftMost = 0;
                rightMost = end;
            }
        }
        
        string res;
        if (rightMost < n - 1) {
            res = s.substr(rightMost + 1, n - rightMost);
            reverse(res.begin(), res.end());
        }
        res = res + s;
        return res;
    }
};