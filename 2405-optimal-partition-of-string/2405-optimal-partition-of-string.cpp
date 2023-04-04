class Solution {
public:
    int partitionString(string s) {
        vector<int> freq(26, 0);
        int res = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (freq[c] == 0) {
                freq[c]++;
            } else {
                res++;
                fill(freq.begin(), freq.end(), 0);
                freq[c] = 1;
            }
        }
        if (accumulate(freq.begin(), freq.end(), 0) > 0) {
            res++;
        }
        return res;
    }
};