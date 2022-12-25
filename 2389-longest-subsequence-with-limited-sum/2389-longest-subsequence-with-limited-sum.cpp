class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> aux(n, 0);
        aux[0] = nums[0];
        for (int i = 1; i < n; i++) {
            aux[i] = aux[i - 1] + nums[i];
        }
        int m = queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = upper_bound(aux.begin(), aux.end(), queries[i]) - aux.begin();
        }
        return res;
    }
};