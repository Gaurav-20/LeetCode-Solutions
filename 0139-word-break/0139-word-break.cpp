class Solution {
public:
    bool find(string s, unordered_set<string>& dict) {
        if (dict.size() == 0) {
            return false;
        }
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    string word = s.substr(j, i - j);
                    if (dict.find(word) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp.back();
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto x : wordDict) {
            dict.insert(x);
        }
        return find(s, dict);
    }
};