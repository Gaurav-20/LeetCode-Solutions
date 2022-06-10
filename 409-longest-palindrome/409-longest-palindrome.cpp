class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char& c : s) {
            freq[c]++;
        }
        int res = 0;
        bool oneOddRemaining = true;
        for (auto it : freq) {
            int count = it.second;
            res += count - (count & 1);
            if ((count & 1) && oneOddRemaining) {
                res++;
                oneOddRemaining = false;
            }
        }
        return res;
    }
};