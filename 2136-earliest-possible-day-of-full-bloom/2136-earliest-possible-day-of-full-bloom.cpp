class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> times(n);
        for (int i = 0; i < n; i++) {
            times[i] = { -growTime[i], plantTime[i] };
        }
        sort(times.begin(), times.end());
        int res = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, cur + times[i].second - times[i].first);
            cur += times[i].second;
        }
        return res;
    }
};