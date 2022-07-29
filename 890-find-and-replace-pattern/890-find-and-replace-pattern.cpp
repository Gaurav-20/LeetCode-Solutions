class Solution {
public:
    vector<int> numericPattern(string pattern) {
        int n = pattern.size();
        if (n == 0) {
            return {};
        }
        vector<int> v;
        int index = 0;
        unordered_map<char,int> mp;
        for (int i = 0; i < n; i++) {
			if (mp.find(pattern[i]) == mp.end()) {
                mp[pattern[i]] = index++;
            }
            v.push_back(mp[pattern[i]]);
        }
        return v;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> vecPattern = numericPattern(pattern);
        vector<string> res;
        for (string word : words) {
            vector<int> patternWord = numericPattern(word);
            if (vecPattern == patternWord) {
                res.push_back(word);
            }
        }
        return res;
    }
};