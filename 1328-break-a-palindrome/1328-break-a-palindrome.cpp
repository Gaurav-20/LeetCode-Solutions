class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) {
            return "";
        }
        int it = 0;
        bool allAs = true;
        while (it < (n / 2)) {
            if (palindrome[it] == 'a') {
                it++;
            } else {
                allAs = false;
                palindrome[it] = 'a';
                break;
            }
        }
        if (allAs) {
            palindrome[n - 1] = 'b';
        }
        return palindrome;
    }
};