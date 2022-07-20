class Solution {
public:    
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, bool> mp;
        int res = 0, n = s.size();
        for (string& word : words) {
            int len = word.size();
            if (mp.find(word) != mp.end()) {
                res += mp[word]; 
                continue;
            }
            int i = 0, j = 0;
            while (i < len && j < n) {
                if (s[j] == word[i]) {
                    i++; 
                }
                j++;
            }
            mp[word] = (i == len);
            res += (i == len);
        }
        return res;
    }
};