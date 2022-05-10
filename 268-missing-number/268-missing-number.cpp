class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int iter = 0, res = nums.size();
        for (int& num : nums) {
            res ^= num;
            res ^= iter++;
        }
        return res;
    }
};