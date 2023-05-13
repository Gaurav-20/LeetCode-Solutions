typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
//     int low, high, zero, one;
    
//     ll solve(int length, vector<ll>& dp) {
//         if (length > high) {
//             return 0;
//         }
//         if (dp[length] != -1) {
//             return dp[length];
//         }
//         if (length >= low && length <= high) {
//             return dp[length] = (1 + solve(length + zero, dp) + solve(length + one, dp)) % MOD;
//         }
//         return dp[length] = (solve(length + zero, dp) + solve(length + one, dp)) % MOD;
//     }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        // this->low = low;
        // this->high = high;
        // this->zero = zero;
        // this->one = one;
        // vector<ll> dp(high + 1, -1LL); // memoization
        // return solve(0LL, dp);
        vector<ll> dp(high + 1, 0LL); // dp[i] means number of string of that length
        dp[0] = 1;
        for (int i = 1; i <= high; i++) {
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            }
            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }
        }
        ll res = 0;
        for (int i = low; i <= high; i++) {
            res = (res + dp[i]) % MOD;
        }
        return res;
    }
};