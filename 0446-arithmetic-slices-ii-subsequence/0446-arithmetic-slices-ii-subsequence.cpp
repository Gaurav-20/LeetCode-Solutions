class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        vector<unordered_map<long long, int>> diff(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                long long d = (long long)nums[i] - nums[j];
                if (!diff[j].count(d)) {
                    diff[i][d]++;
                } 
                else {
                    res += diff[j][d];
                    diff[i][d] += diff[j][d] + 1;
                }
            }
        }
        return res;
    }
};