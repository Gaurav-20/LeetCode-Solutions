int dp[21][21];

class Solution {
public:
    int solve(vector<int>& arr, int low, int high) {
        if (low > high) {
            return 0;
        }
        if (low == high) {
            return arr[low];
        }
        if (dp[low][high] != -1) {
            return dp[low][high];
        }
        int way1 = arr[low] + min(solve(arr, low + 2, high), solve(arr, low + 1, high - 1));
        int way2 = arr[high] + min(solve(arr, low + 1, high - 1), solve(arr, low, high - 2));
        return dp[low][high] = max(way1, way2);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans1 = solve(nums, 0, nums.size() - 1);
        int ans2 = total - ans1;
        return ans1 >= ans2;
    }
};