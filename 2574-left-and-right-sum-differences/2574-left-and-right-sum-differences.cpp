class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        for (int i = 1; i < n; i++) {
            leftSum[i] = nums[i - 1] + leftSum[i - 1];
        }
        vector<int> rightSum(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            rightSum[i] = nums[i + 1] + rightSum[i + 1];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = abs(leftSum[i] - rightSum[i]);
        }
        return res;
    }
};