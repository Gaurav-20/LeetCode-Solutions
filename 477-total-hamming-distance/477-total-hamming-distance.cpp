class Solution {
public:
    
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
            for (int& i : nums) {
                if (i == 0) {
                    zeroCount++;
                }
                bit[i % 2]++;
                i >>= 1;
            }
            res += bit[0] * bit[1];
            if (zeroCount == n) {
                return res;
            }
        }
        return res;
    }
};