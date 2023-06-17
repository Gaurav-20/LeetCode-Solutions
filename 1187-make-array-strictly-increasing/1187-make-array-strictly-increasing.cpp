class Solution {
public:
    int n, m;
    
    int solve(int i, int prev, vector<int>& arr1, vector<int>& arr2, vector<vector<int>> &dp) {
        if (i == n) {
            return 0;
        }
        int j = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (j == m && arr1[i] <= prev) {
            return dp[i][j] = 2e9;
        }
        int pick = 2e9;
        int notPick = 2e9;
        if (j != m) {
            pick = 1 + solve(i + 1, arr2[j], arr1, arr2, dp);
        }
        if (arr1[i] > prev) {
            notPick = solve(i + 1, arr1[i], arr1, arr2, dp);
        }
        return dp[i][j] = min(pick, notPick);
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        n = arr1.size(), m = arr2.size();
        sort(arr2.begin(), arr2.end());
        vector<vector<int>> dp(n, vector<int>(m + 1, -1));
        int res = solve(0, -1, arr1, arr2, dp);
        return (res == 2e9) ? -1 : res;
    }
};