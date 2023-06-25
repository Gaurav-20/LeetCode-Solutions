class Solution {
public:
    int dfs(int i, int f, int l, int n, vector<string> &words, vector<vector<vector<int>>> &dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i][f][l] != -1) {
            return dp[i][f][l];
        }
        int opt1 = 1e9, opt2 = 1e9;
        if (l + 'a' == words[i][0]) {
            opt1 = words[i].size() - 1 + dfs(i + 1, f, words[i].back() - 'a', n, words, dp);
        }
        if (f + 'a' == words[i].back()) {
            opt2 = words[i].size() - 1 + dfs(i + 1, words[i][0] - 'a', l, n, words, dp);
        }        
        int opt3 = words[i].size() + dfs(i + 1, f, words[i].back() - 'a', n, words, dp);
        int opt4 = words[i].size() + dfs(i + 1, words[i][0] - 'a', l, n, words, dp);
        return dp[i][f][l] = min({opt1, opt2, opt3, opt4});
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        vector<vector<vector<int>>> 
            dp(n, vector<vector<int>>(26, vector<int>(26, -1)));
        return words[0].size() + 
            dfs(1, words[0][0] - 'a', words[0].back() - 'a', n, words, dp);
    }
};