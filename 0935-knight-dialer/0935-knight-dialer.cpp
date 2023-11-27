const int MOD = 1e9 + 7;

class Solution {
public:
    unordered_map<int, vector<int>> moves = {
        { 0, { 4, 6 } },
        { 1, { 6, 8 } },
        { 2, { 7, 9 } },
        { 3, { 4, 8 } },
        { 4, { 0, 3, 9 } },
        { 5, {} },
        { 6, { 0, 1, 7 } },
        { 7, { 2, 6 } },
        { 8, { 1, 3 } },
        { 9, { 2, 4 } }
    };
    
    int knightDialer(int n) {
        vector<int> dp(10, 1);
        for (int len = 2; len <= n; len++) {
            vector<int> dpCopy = dp;
            for (int button = 0; button < 10; button++) {
                dp[button] = 0;
                for (auto it: moves[button]) {
                    dp[button] = (dp[button] + dpCopy[it]) % MOD;
                }
            }
        }
        int res = 0;
        for (int button = 0; button < 10; button++) {
            res = (res + dp[button]) % MOD;
        }
        return res;
    }
};