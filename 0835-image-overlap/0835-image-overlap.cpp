class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> a, b;
        int n = img1.size();
        unordered_map<int, int> count;
        for (int i = 0; i < n * n; i++) {
            if (img1[i / n][i % n] == 1) {
                a.push_back(i / n * 100 + i % n);
            }
        }
        for (int i = 0; i < n * n; i++) {
            if (img2[i / n][i % n] == 1) {
                b.push_back(i / n * 100 + i % n);
            }
        }
        for (int i : a) {
            for (int j : b) {
                count[i - j]++;
            }
        }
        int res = 0;
        for (auto it : count) {
            res = max(res, it.second);
        }
        return res;
    }
};