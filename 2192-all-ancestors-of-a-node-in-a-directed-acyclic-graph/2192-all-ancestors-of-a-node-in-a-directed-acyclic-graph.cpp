class Solution {
public:
    void dfs(int x, int curr, vector<vector<int>>& res, vector<vector<int>>& directChild) {
        for (auto& ch: directChild[curr]) {
            if (res[ch].size() == 0 || res[ch].back() != x) {
                res[ch].push_back(x);
                dfs(x, ch, res, directChild);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n), directChild(n);
        for (auto& e : edges) {
            directChild[e[0]].push_back(e[1]);
        }
        for (int i = 0; i < n; i++) {
            dfs(i, i, res, directChild);
        }
        return res;
    }
};