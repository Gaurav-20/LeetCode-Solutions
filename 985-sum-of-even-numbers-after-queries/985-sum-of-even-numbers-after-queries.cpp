class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size(), n = nums.size();
        vector<int> res(q);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                sum += nums[i];
            }
        }
        for (int i = 0; i < q; i++) {
            int val = queries[i][0], index = queries[i][1];
            int cur = nums[index];
            bool evenVal = val % 2 == 0;
            bool evenCur = cur % 2 == 0;
            if (evenVal && evenCur) {
                sum += val;
            } else if (!evenVal && !evenCur) {
                sum += cur + val;
            } else if (!evenVal && evenCur) {
                sum -= cur;
            } else {
                // do nothing
            }
            nums[index] += val;
            res[i] = sum;
        }
        return res;
    }
};