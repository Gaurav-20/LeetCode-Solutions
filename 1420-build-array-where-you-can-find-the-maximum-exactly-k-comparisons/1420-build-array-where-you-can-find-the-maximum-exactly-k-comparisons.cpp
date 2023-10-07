class Solution {
public:
    int dp[51][101][51], res[51][101][51], MOD = 1e9 + 7;

    int numOfArrays(int n, int m, int k) {
        for (int j = 0; j <= m; j++) {
            dp[1][j][1] = 1;
            res[1][j][1] = j;
        }

        for (int len = 2; len <= n; len++) {
            for (int maxElement = 1; maxElement <= m; maxElement++) {
                for (int cost = 1; cost <= k; cost++) {
                    /*
                    In this first case, we can append any element from [1, maxElement]
                    to the end of the array.
                    */
                    dp[len][maxElement][cost] = (1LL * maxElement * dp[len - 1][maxElement][cost]) % MOD;
                    
                    /*
                    In this second case, we can append the element "maxElement" to the end of the array. 
                    for (int i = 1; i < maxElement; i++)
                        dp[len][maxElement][cost] += ways[len - 1][i][cost - 1];
                    */
                    dp[len][maxElement][cost] =
                        (dp[len][maxElement][cost] + res[len - 1][maxElement-1][cost-1]) % MOD;
                    res[len][maxElement][cost] =
                        (res[len][maxElement - 1][cost] + dp[len][maxElement][cost]) % MOD;
                }
            }
        }
        return res[n][m][k];
    }
};