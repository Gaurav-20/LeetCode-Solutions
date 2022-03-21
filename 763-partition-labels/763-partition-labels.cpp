class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
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
        res.push_back({start, end});
        return res;
    }

    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < size(s); i++) {
            char c = s[i];
            if (mp.find(c) == mp.end()) {
                mp[c] = { i, i };
            } else {
                mp[c][1] = i;
            }
        }
        vector<vector<int>> vec;
        for (auto it : mp) {
            vec.push_back(it.second);
        }
        vec = mergeIntervals(vec);
        vector<int> res;
        for (auto it : vec) {
            res.push_back(it[1] - it[0] + 1);
        }
        return res;
    }
};