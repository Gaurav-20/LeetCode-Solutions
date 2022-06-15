bool comp(const string& a, const string& b) {
    return a.size() < b.size();
}

class Solution {
public:
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int> dp;
        int res = 0;
        for (string word : words) {
            for (int i = 0; i < word.size(); i++) {
                string curr = word.substr(0, i) + word.substr(i + 1);
                dp[word] = max(dp[word], dp[curr] + 1);
            }
            res = max(res, dp[word]);
        }
        return res;
    }
};