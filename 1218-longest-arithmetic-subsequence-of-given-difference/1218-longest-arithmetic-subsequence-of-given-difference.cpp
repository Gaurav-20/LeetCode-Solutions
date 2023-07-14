class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> index;
        vector<int> dp(n, 1);
        index[arr[0]] = 0;
        for (int i = 1; i < n; i++) {
            int prev = arr[i] - difference;
            if (index.find(prev) != index.end()) {
                dp[i] = max(dp[i], dp[index[prev]] + 1);
            }
            index[arr[i]] = i;
        }
        return *max_element(dp.begin(), dp.end());
    }
};