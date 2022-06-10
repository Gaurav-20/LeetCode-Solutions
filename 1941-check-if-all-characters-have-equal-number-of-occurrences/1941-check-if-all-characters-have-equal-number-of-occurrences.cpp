class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        for (auto c : s) {
            freq[c]++;
        }
        int count = freq[s[0]];
        for (auto it : freq) {
            if (it.second != count) {
                return false;
            }
        }
        return true;
    }
};