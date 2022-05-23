int dp[605][105][105];

class Solution {
public:
    int getNumberOfZeroes(string str) {
        int count = 0;
        for (char c : str) {
            if (c == '0') {
                count++;
            }
        }
        return count;
    }
    
    int solve(vector<string>& strs, int it, int len, int m, int n) {
        if (it >= len) {
            return 0;
        }
        if (dp[it][m][n] != -1) {
            return dp[it][m][n];
        }
        int numZeroes = getNumberOfZeroes(strs[it]);
        int numOnes = strs[it].size() - numZeroes;
        if (m < numZeroes || n < numOnes) {
            return dp[it][m][n] = solve(strs, it + 1, len, m, n);
        }
        return dp[it][m][n] = max(
                                solve(strs, it + 1, len, m, n),
                                1 + solve(strs, it + 1, len, m - numZeroes, n - numOnes)
                                );
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        int len = strs.size();
        return solve(strs, 0, len, m, n);
    }
};