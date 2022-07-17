int dp[505][505];

class Solution {
public:
    int n;
    
    int solve(vector<int>& arr, int it, int time) {
        if (it >= n) {
            return 0;
        }
        if (dp[it][time] != -1) {
            return dp[it][time];
        }
        return dp[it][time] = max(
                                time * arr[it] + solve(arr, it + 1, time + 1), // include
                                solve(arr, it + 1, time) // exclude
                            );
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        memset(dp, -1, sizeof(dp));
        return solve(satisfaction, 0, 1);
    }
};