class Solution {
public:
    int count(string s, int left, int right, int len) {
        int res = 0;
        while (left >= 0 && right < len && s[left] == s[right]) {
            res++;
            left--;
            right++;
        }
        return res;
    }
    
    int countSubstrings(string s) {
        int res = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            res += count(s, i, i, len);
            res += count(s, i, i + 1, len);
        }
        return res;
    }
};