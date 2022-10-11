class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int res = 0, m = mentors.size(), n = mentors[0].size();
        vector<int> perms(m);
        for (int i = 0; i < m; i++) {
            perms[i] = i;
        }
        do {
            int count = 0;
            for (int i = 0; i < m; i++) {
                int it = perms[i];
                for (int j = 0; j < n; j++) {
                    count += students[it][j] == mentors[i][j];
                }
            }
            res = max(res, count);
        } while (next_permutation(perms.begin(), perms.end()));
        return res;
    }
};