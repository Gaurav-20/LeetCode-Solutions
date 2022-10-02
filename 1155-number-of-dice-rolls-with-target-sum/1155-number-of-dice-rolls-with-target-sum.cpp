const int MOD = 1e9 + 7;

class Solution {
public:
    long long dp[35][1005];
    
    int numDice;
    int numFaces;
    int target;
    
    int solve(int n, int sum) {
        if (n == 0) {
            return sum == target;
        }
        if (sum < 0 || sum > target) {
            return 0;
        }
        if (dp[n][sum] != -1) {
            return dp[n][sum];
        }
        long long res = 0;
        for (int i = 1; i <= numFaces; i++) {
            res = (res + solve(n - 1, sum + i)) % MOD;
        }
        return dp[n][sum] = res;
    }
    
    int numRollsToTarget(int n, int k, int sum) {
        target = sum;
        numDice = n;
        numFaces = k;
        memset(dp, -1, sizeof(dp));
        return solve(n, 0);
    }
};