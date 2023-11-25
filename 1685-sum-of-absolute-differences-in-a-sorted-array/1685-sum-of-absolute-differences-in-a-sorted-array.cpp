class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            right += nums[i];
        }
        for (int i = 0; i < n; i++) {
            right -= nums[i];
            int res1 = (nums[i] * i) - left;
            int res2 = right - (nums[i] * (n - i - 1));
            res.push_back(res1 + res2);
            left += nums[i];
        }
        return res;
    }
};