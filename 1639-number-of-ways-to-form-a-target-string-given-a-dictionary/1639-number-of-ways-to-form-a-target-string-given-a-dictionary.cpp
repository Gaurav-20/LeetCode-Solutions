typedef long long ll;
const ll MOD = 1e9 + 7;
#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD

class Solution {
public:
    int n, m;
    
    ll solve(vector<vector<ll>>& freq, string& target, vector<vector<ll>>& dp, 
             int colIdx, int targetIdx) {
        if (targetIdx == m) {
            return 1LL;
        }
        if (colIdx == n) {
            return 0LL;
        }
        if (dp[colIdx][targetIdx] != -1) {
            return dp[colIdx][targetIdx];
        }
        dp[colIdx][targetIdx] = solve(freq, target, dp, colIdx + 1, targetIdx);
        int targetCharIdx = target[targetIdx] - 'a';
        dp[colIdx][targetIdx] += mul(freq[colIdx][targetCharIdx],
                                     solve(freq, target, dp, colIdx + 1, targetIdx + 1));
        return dp[colIdx][targetIdx] % MOD;
    }
    
    int numWays(vector<string>& words, string target) {
        n = words[0].size(), m = target.size();
        vector<vector<ll>> freq(n, vector<ll>(26, 0));
        for (string word : words) {
            for (int i = 0; i < n; i++) {
                int ch = word[i] - 'a';
                freq[i][ch]++;
            }
        }
        vector<vector<ll>>dp(n, vector<ll>(m, -1));
        return solve(freq, target, dp, 0, 0);
    }
};