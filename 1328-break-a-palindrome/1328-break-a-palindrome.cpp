class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) {
            return "";
        }
        int low = 0, high = n - 1;
        bool allAs = true;
        while (low < high) {
            if (palindrome[low] == 'a') {
                low++;
                high--;
            } else {
                allAs = false;
                palindrome[low] = 'a';
                break;
            }
        }
        if (allAs) {
            palindrome[n - 1] = 'b';
        }
        return palindrome;
    }
};