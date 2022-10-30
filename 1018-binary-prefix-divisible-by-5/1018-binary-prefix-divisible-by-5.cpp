class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> res(n);
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr = ((curr * 2) + nums[i]) % 5;
            res[i] = curr % 5 == 0;
        }
        return res;
    }
};