bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second < b.second) {
        return true;
    } else if (a.second > b.second) {
        return false;
    } else {
        return a.first < b.first;
    }
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> weak;

        for (int i = 0; i < mat.size(); i++) {
            int s = accumulate(mat[i].begin(), mat[i].end(), 0);
            weak.push_back({i, s});
        }
        sort(weak.begin(), weak.end(), comp);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(weak[i].first);    
        }
        return res;
    }
};