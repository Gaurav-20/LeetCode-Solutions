class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            string word = words[i];
            if (isVowel(word[0]) && isVowel(word.back())) {
                prefix[i] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }
        vector<int> res;
        for (vector<int> query : queries) {
            int l = query[0], r = query[1];
            if (l == 0) {
                res.push_back(prefix[r]);
            } else {
                res.push_back(prefix[r] - prefix[l - 1]);
            }
        }
        return res;
    }
};