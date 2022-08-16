class Solution {
public:
    // It can be done in two passes by first storing all the chars and then iterating to see
    // from start which char has frequency as 1
    int firstUniqChar(string s) {
        int n = s.size();
        if (n == 0) {
            return -1;
        }
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            freq[idx]++;
        }
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (freq[idx] == 1) {
                return i;
            }
        }
        return -1;
    }
};