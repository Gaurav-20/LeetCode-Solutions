class Solution {
public:
    bool isSubstring(string str, string pattern) {
        if (str.find(pattern) != string::npos) {
            return str.find(pattern) >= 0;
        }
        return false;
    }
    
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if (n <= 1) {
            return false;
        }
        string merged = "";
        for (int i = 1; i < n; i++) {
            merged += s[i];
        }
        for (int i = 0; i < n - 1; i++) {
            merged += s[i];
        }
        return isSubstring(merged, s);
    }
};