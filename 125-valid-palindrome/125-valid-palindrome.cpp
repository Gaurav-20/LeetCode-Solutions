class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (auto c : s) {
            char x = tolower(c);
            if ((x >= 'a' && x <= 'z')
                || (x >= '0' && x <= '9')) {
                t += x;
            }
        }
        int low = 0, high = t.size() - 1;
        while (low < high) {
            if (t[low] != t[high]) {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};