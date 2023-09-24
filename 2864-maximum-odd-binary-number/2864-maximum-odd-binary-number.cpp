class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int countOnes = 0;
        for (char& c: s) {
            countOnes += c == '1';
        }
        for (int i = 0; i < countOnes - 1; i++) {
            s[i] = '1';
        }
        for (int i = countOnes - 1; i < n - 1; i++) {
            s[i] = '0';
        }
        s[n - 1] = '1';
        return s;
    }
};