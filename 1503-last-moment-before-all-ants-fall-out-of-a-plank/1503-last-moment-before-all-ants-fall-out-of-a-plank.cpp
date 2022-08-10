class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = INT_MIN;
        for (auto it : left) {
            res = max(res, it);
        }
        for (auto it : right) {
            res = max(res, n - it);
        }
        return res;
    }
};