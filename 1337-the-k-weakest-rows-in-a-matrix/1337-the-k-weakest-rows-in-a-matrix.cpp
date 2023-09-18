class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> vec(m);
        for (int i = 0; i < m; i++) {
            vec[i] = { accumulate(mat[i].begin(), mat[i].end(), 0), i };
        }
        sort(vec.begin(), vec.end());
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = vec[i].second;
        }
        return res;
    }
};