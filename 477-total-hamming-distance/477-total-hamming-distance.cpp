class Solution {
public:
    int countBits(int n) {
        int ct = 0;
        while (n > 0) {
            ct++;
            n = n & (n - 1);
        }
        return ct;
    }
    
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if (n < 2) {
            return res;
        }
        vector<int> bit = { 0, 0 };
        while (true) {
            int zeroCount = 0;
            bit[0] = 0;
            bit[1] = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    zeroCount++;
                }
                bit[nums[i] % 2]++;
                nums[i] >>= 1;
            }
            res += bit[0] * bit[1];
            if (zeroCount == n) {
                return res;
            }
        }
        return res;
    }
};