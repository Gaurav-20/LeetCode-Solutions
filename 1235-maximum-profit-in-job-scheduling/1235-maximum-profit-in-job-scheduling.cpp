bool comp(const vector<int> &a, const vector<int> &b) {
    return (a[0] <= b[0]); // compare as per start time
}

class Solution {
public:
    int n;
    vector<vector<int>> arr;
    vector<int> dp;

    int find(int i) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        vector<int> t = { arr[i][1], -1, -1 }; // start, end and profit respectively
        int id = lower_bound(arr.begin(), arr.end(), t) - arr.begin();

        //we either take the current index or return
        int ans = arr[i][2] + find(id);
        ans = max(ans, find(i + 1));
        return dp[i] = ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        for (int i = 0; i < n; i++) {
            arr.push_back({ startTime[i], endTime[i], profit[i] });
        }
        dp.resize(n, -1);
        sort(arr.begin(), arr.end(), comp);
        return find(0);
    }
};