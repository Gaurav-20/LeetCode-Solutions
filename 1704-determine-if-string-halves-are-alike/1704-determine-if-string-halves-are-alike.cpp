class Solution {
public:
    bool isPrime(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    bool halvesAreAlike(string s) {
        int count = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (isPrime(tolower(s[i]))) {
                if (i < n / 2) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return count == 0;
    }
};