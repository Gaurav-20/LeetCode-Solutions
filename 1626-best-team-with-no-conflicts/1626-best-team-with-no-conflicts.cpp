class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<vector<int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = { ages[i], scores[i] };
        }
        sort(vec.begin(), vec.end());
        vector<int> dp(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = vec[i][1];
            for (int j = i - 1; j >= 0; j--) {
                if (vec[i][1] >= vec[j][1]){
                    dp[i] = max(dp[i], dp[j] + vec[i][1]); 
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};