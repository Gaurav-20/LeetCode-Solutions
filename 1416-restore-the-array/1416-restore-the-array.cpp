int n;
const long long MOD = 1e9 + 7;

class Solution {
public:
    int solve(string& s, long long k, int i, vector<int>& dp) {
        if (i == n) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int res = 0;
        long long num = 0;
        for (int j = i; j < n; j++) {
            num = num * 10 + (s[j] - '0');
            if (num > k) {
                break;
            }
            res = (res + solve(s, k, j + 1, dp)) % MOD;
        }
        return dp[i] = res;
    }
    
    int numberOfArrays(string s, int k) {
        n = s.size();
        vector<int> dp(n, -1);
        return solve(s, k, 0, dp);
    }
};