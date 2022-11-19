class Solution {
public:
    int orientation(vector<int>& p, vector<int>& q, vector<int>& r) {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        sort(trees.begin(), trees.end());
        vector<vector<int>> hull;
        for (int i = 0; i < n; i++) {
            while (hull.size() > 1 && 
                   orientation(hull[hull.size() - 2], hull[hull.size() - 1], trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }
        // if all points along a line, hull.size() is n after left to right procedure
        if (hull.size() == n) {
            return hull;
        }
        // right to left
        for (int i = n - 2; i >= 0; i--) {
            while (hull.size() > 1 && 
                   orientation(hull[hull.size() - 2], hull[hull.size() - 1], trees[i]) < 0) { 
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }
        hull.pop_back();

        return hull;
    }
};