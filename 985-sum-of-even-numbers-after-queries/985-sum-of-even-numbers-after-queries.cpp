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
            if (nums[index] % 2 == 0) {
                sum -= nums[index];
            }
            nums[index] += val;
            if (nums[index] % 2 == 0) {
                sum += nums[index];
            }
            res[i] = sum;
        }
        return res;
    }
};