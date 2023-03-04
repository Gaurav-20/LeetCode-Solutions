const long long MOD = 1e9 + 7;

long long fastpow(long long a, long long b, long long m = MOD) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

class Solution {
public:
    int mergedSize(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int len = size(intervals);
        int start = intervals[0][0], end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end && intervals[i][1] <= end) {
                continue;
            } else if (intervals[i][0] <= end) {
                end = intervals[i][1];
            } else {
                res.push_back({ start, end });
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({ start, end });
        return res.size();
    }
    
    int countWays(vector<vector<int>>& ranges) {
        long long size = mergedSize(ranges);
        return fastpow(2LL, size);
    }
};