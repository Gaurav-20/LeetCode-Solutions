class Solution {
public:
    unordered_set<string> wordSet;
    unordered_map<string, bool> dp;
    
    bool containsWord(string word) {
        return wordSet.find(word) != wordSet.end();
    }
    
    bool dfs(string word) {
        if (dp.find(word) != dp.end()) {
            return dp[word];
        }
        for (int i = 1; i < word.size(); i++) {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i, word.size() - i + 1);
            if (containsWord(prefix) && (containsWord(suffix) || dfs(suffix))) {
                return dp[word] = true;
            }
        }
        return dp[word] = false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (string word : words) {
            wordSet.insert(word);
        }
        vector<string> res;
        for (string word : words) {
            if (dfs(word)) {
                res.push_back(word);
            }
        }
        return res;
    }
};