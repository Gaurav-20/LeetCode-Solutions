class Solution {
public:
    
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> res(n);
        long long rem = 0;
        for (int i = 0; i < n; i++) {
            long long cur = (rem * 10 + (word[i] - '0')) % m;
            res[i] = cur == 0;
            rem = cur;
        }
        return res;
    }
};