typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int low, high, zero, one;
    
    ll solve(int length, vector<ll>& dp) {
        if (length > high) {
            return 0;
        }
        if (dp[length] != -1) {
            return dp[length];
        }
        if (length >= low && length <= high) {
            return dp[length] = (1 + solve(length + zero, dp) + solve(length + one, dp)) % MOD;
        }
        return dp[length] = (solve(length + zero, dp) + solve(length + one, dp)) % MOD;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        this->low = low;
        this->high = high;
        this->zero = zero;
        this->one = one;
        vector<ll> dp(high + 1, -1LL);
        return solve(0LL, dp);
    }
};