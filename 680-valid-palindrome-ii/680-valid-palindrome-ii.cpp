class Solution {
public:
    bool checkPalindrome(string s, int low, int high) {
        while (low < high) {
            if (s[low] != s[high]) {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            if (s[low] != s[high]) {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
            }
            low++;
            high--;
        }
        return true;
    }
};