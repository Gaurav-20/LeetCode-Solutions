class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for (char c : s) {
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int keep = 0, prev = INT_MAX;
        for (int f : freq) {
            if (f == 0 || prev == 0) {
                break;
            }
            prev = min(f, prev - 1);
            keep += prev;
        }
        return s.size() - keep;
    }
};