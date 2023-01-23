class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
        for (auto& e : trust) {
            outDegree[e[0]]++, inDegree[e[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (outDegree[i] == 0 && inDegree[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};