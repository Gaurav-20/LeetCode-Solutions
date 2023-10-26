const int MOD = 1e9 + 7;
#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD

class Solution {
public:
    void solveForRoot(int root, map<int, long long>& dp) {
        long long count = 1;
        for (auto it: dp) {
            if (root % it.first == 0 && dp[root / it.first]) {
                count = (count + mul(it.second, dp[root / it.first])) % MOD;
            }
        }
        dp[root] = count;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        map<int, long long> dp;
        sort(arr.begin(), arr.end());
        for (auto root: arr) {
            solveForRoot(root, dp);
        }
        long long res = 0;
        for (auto it: dp) {
            res = (res + it.second) % MOD;
        }
        return (int) res;
    }
};