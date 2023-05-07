class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // similar to LIS in O(nlogn)
        vector<int> res;
        vector<int> dp;
        for (int i = 0; i < obstacles.size(); i++) {
            int len = lower_bound(dp.begin(), dp.end(), obstacles[i] + 1) - dp.begin();
            if (len == dp.size()) {
                dp.push_back(obstacles[i]);
            } else {
                dp[len] = obstacles[i];
            }
            res.push_back(len + 1);
        }
        return res;
    }
};